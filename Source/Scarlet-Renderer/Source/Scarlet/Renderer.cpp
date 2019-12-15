#include "Scarlet/Renderer.h"

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
        Renderable * r = scene.getObject(ray);
        if (!r) continue;
        // Vector3F normal = r->getNormal(ray.origin + ray.direction * r->intersect(ray));
        c.r = abs(ray.direction.x);
        c.g = abs(ray.direction.y);
        c.b = ray.direction.z;
        m_RenderBuffer.setColor(i, c);
    }
}