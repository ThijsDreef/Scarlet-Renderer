#include "Scarlet/Renderables/Plane.h"
#include <cmath>

Plane::Plane(Vector3F& normal) {
    m_Normal = normal.unit();
}

Vector3F Plane::getNormal(const Vector3F& hitPosition) {
    return m_Normal;
}

float Plane::intersect(const Ray& ray) {
    Ray transformed = transformRay(ray);
    float denom = (transformed.direction.dot(m_Normal));
    if (-denom > 0) {
        Vector3F m = transformed.origin;
        return m.dot(m_Normal) / denom; ; 
    } 
    return -1;
}