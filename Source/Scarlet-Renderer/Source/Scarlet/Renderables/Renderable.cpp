#include "Scarlet/Renderables/Renderable.h" 

void Renderable::translate(Vector3F translation) {
    m_Translation += translation;
    recalcTransform();
}

void Renderable::rotate(Vector3F rotation) {
    m_Rotation += rotation;
    recalcTransform();
}

void Renderable::scale(Vector3F scale) {
    m_Scale += scale;
    recalcTransform();
}

void Renderable::recalcTransform() {
    m_Transform.translate(m_Translation);
    m_Transform.rotateBy(m_Rotation);
    m_Transform.scaleBy(m_Scale);

    m_InverseTransform = m_Transform.inverse();
}

Ray Renderable::transformRay(const Ray& ray) {
    Ray transformed;
    transformed.origin = m_InverseTransform.multByVector(ray.origin);
    transformed.direction = m_InverseTransform.multDirection(ray.direction).unit();
    return transformed;
}