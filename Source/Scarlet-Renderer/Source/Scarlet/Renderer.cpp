#include "Scarlet/Renderer.h"
#include <cmath>
#include <iostream>
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
    std::vector<Ray> rays = camera.calculateRays(m_RenderBuffer.getWidth(), m_RenderBuffer.getHeight());
    Color c;

    for (unsigned int i = 0; i < rays.size(); i++) {
        Ray ray = rays[i];
        ray.origin = camera.m_Transform.multByVector(ray.origin);
        ray.direction = camera.m_Transform.multDirection(ray.direction).unit();

        Renderable * renderable = scene.getObject(ray);
        if (!renderable) continue;

        Ray tr = renderable->transformRay(ray);
        
        Vector3F hit = tr.origin + (tr.direction * renderable->intersect(ray));
        
        // hit = 

        if ((hit - Vector3F(0, 0, -5)).length() > 1) {
            std::cout << tr.origin.x << " " << tr.origin.y << " " << tr.origin.z << "\n";
            std::cout << tr.direction.x << " " << tr.direction.y << " " << tr.direction.z << "\n";
        
            std::cout << hit.x << " " << hit.y << " " << hit.z << "\n";
            std::cout << "error";
            return;
        }


        // std::cout << "before: "<< hit.x << " " << hit.y << " " << hit.z << "\n";
        

        // std::cout << "after: "<< hit.x << " " << hit.y << " " << hit.z << "\n";
        Vector3F normal = renderable->getNormal(hit);
        
        float lum = (normal.dot(Vector3F(0.2, -0.5, -0.6).unit()));

        int t = static_cast<int>(ceil(abs(hit.x) + 0.5)) % 2;
        t += static_cast<int>(ceil(abs(hit.y) + 0.5)) % 2;
        // t += static_cast<int>(ceil(abs(hit.z) + 0.5)) % 2;

        if (t > 1) t = 0;
        

        
        if (lum < 0.2) lum = 0.2;
        c.r = lum * t;
        c.g = lum * t;
        c.b = lum * (1.0 - t);
        c.r = abs(normal.x);
        c.g = abs(normal.y);
        c.b = abs(normal.z);

        m_RenderBuffer.setColor(i, c);
    }
}