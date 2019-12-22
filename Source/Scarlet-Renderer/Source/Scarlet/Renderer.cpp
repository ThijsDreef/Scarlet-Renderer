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
    Timer t;
    std::vector<Ray> rays = camera.calculateRays(m_RenderBuffer.getWidth(), m_RenderBuffer.getHeight());
    Color c;

    for (unsigned int i = 0; i < rays.size(); i++) {
        Ray ray = rays[i];

        ray.origin = camera.m_Transform.multByVector(ray.origin);
        ray.direction = camera.m_Transform.multDirection(ray.direction).unit();

        Renderable * renderable = scene.getObject(ray);
        if (!renderable) continue;
        
        Ray tr = renderable->transformRay(ray);
        Vector3F objectSpaceHit = tr.origin - (tr.direction * renderable->intersect(ray));
        Vector3F hit = ray.origin + ray.direction * renderable->intersect(ray);
 
        Vector3F normal = renderable->getNormal(objectSpaceHit);
        
        float lum = (normal.dot(Vector3F(0.2, -0.5, -0.6).unit()));
        
        lum = std::max(lum, 0.2f);
        Material* mat = scene.getMaterial(renderable->m_materialId);
        c = mat->getMaterialColor(renderable, objectSpaceHit);
        c.r *= lum;
        c.g *= lum;
        c.b *= lum;

        m_RenderBuffer.setColor(i, c);
    }
    double passedTime = t.getElapsed();
    std::cout << "render took: " << passedTime << " seconds\n";
    std::cout << std::fixed << "average ray took: " << (passedTime / rays.size()) << " seconds\n";
}