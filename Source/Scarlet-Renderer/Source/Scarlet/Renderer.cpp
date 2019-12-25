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

void Renderer::renderScene(Scene& scene, Camera & camera) {
    unsigned int pd = 1;
    Timer t;
    std::vector<Ray> rays = camera.calculateRays(m_RenderBuffer.getWidth(), m_RenderBuffer.getHeight(), pd);
    Color c;
    Mat4x4 inverseCameraTransform = camera.m_Transform.inverse();

    for (unsigned int i = 0; i < rays.size(); i += pd) {
        c = Color(0, 0, 0);
        for (unsigned int j = 0; j < pd; j++) {
            Ray ray = rays[i + j];

            ray.origin = camera.m_Transform.multByVector(ray.origin);
            ray.direction = camera.m_Transform.multDirection(ray.direction).unit();

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
        c.r /= pd;
        c.g /= pd;
        c.b /= pd;

        m_RenderBuffer.setColor(i / pd, c);
    }
    double passedTime = t.getElapsed();
    std::cout << "render took: " << passedTime << " seconds\n";
    std::cout << std::fixed << "average ray took: " << (passedTime / rays.size()) << " seconds\n";
}