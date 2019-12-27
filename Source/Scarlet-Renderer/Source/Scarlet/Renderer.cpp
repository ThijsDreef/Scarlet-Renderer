#include "Scarlet/Renderer.h"
#include <cmath>
#include <iostream>
#include <algorithm>

Renderer::Renderer() {
    
}

Renderer::~Renderer() {

}

void Renderer::setRenderDimensions(unsigned int w, unsigned int h) {
    m_RenderBuffer.setRenderBufferSize(w, h);
}

void Renderer::writeRenderBuffer(const char* fileName) {
    m_RenderBuffer.writeBuffer(fileName);
}

void Renderer::renderPixels(unsigned int start, unsigned int end, Scene& scene, Camera& camera) {
        std::cout << start << " " << end << "\n";

    for (unsigned int i = start; i < end; i++) {
        // std::cout << i << "\n";
        renderPixel(i, scene, camera);
    }
}


void Renderer::renderPixel(unsigned int id, Scene& scene, Camera& camera) {
    Color c;
    for (unsigned int aa = 0; aa < m_aaFactor; aa++) {
        Ray ray = camera.getRayByIndex(id, aa);

        ray.origin = camera.m_Transform.multByVector(ray.origin);
        ray.direction = camera.m_Transform.multByDirection(ray.direction).unit();

        Renderable * renderable = scene.getObject(ray);
        if (!renderable) continue;
        
        Ray tr = renderable->transformRay(ray);
        Vector3F objectSpaceHit = tr.origin - (tr.direction * renderable->intersect(ray));
        Vector3F hit = ray.origin + ray.direction * renderable->intersect(ray);

        Vector3F normal = renderable->getNormal(objectSpaceHit);
        
        float lum = (normal.dot(Vector3F(0.2, 0.5, -0.6).unit()));
        
        lum = std::max(lum, 0.2f);
        Material* mat = scene.getMaterial(renderable->m_materialId);
        Color rc = mat->getMaterialColor(renderable, objectSpaceHit);
        c.r += lum * rc.r;
        c.g += lum * rc.g;
        c.b += lum * rc.b;
    }
    c.r /= m_aaFactor;
    c.g /= m_aaFactor;
    c.b /= m_aaFactor;
    m_RenderBuffer.setColor(id, c);

}

void Renderer::renderScene(Scene& scene, Camera & camera) {
    unsigned int pixels = m_RenderBuffer.getHeight() * m_RenderBuffer.getWidth();
    unsigned int rays = camera.calculateRays(m_RenderBuffer.getWidth(), m_RenderBuffer.getHeight(), m_aaFactor);    
    Timer t;
    Mat4x4 inverseCameraTransform = camera.m_Transform.inverse();
    for (unsigned int i = 0; i < pixels; i++) {
        renderPixel(i, scene, camera);
    }
    double passedTime = t.getElapsed();
    std::cout << "render took: " << passedTime << " seconds\n";
    std::cout << std::fixed << "average ray took: " << (passedTime / rays) << " seconds\n";
}

void Renderer::renderSceneMultiThreaded(Scene& scene, Camera& camera, unsigned int threadCount) {
    std::vector<std::thread> threads;
    // threads.reserve(threadCount);
    unsigned int pixels = m_RenderBuffer.getHeight() * m_RenderBuffer.getWidth();
    unsigned int rays = camera.calculateRays(m_RenderBuffer.getWidth(), m_RenderBuffer.getHeight(), m_aaFactor);  
    for (unsigned int i = 0; i < threadCount; i++) {
        threads.push_back(std::thread(&Renderer::renderPixels, this, static_cast<unsigned int>(((i + 0.0) / threadCount) * pixels), static_cast<unsigned int>(((i + 1.0) / threadCount) * pixels), scene, camera));
    }

    for (unsigned int i = 0; i < threads.size(); i++) {
        if (threads[i].joinable())
            threads[i].join();
    }
}