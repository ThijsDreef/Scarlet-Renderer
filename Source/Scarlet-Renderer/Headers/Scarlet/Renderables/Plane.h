#pragma once
#include "Scarlet/Renderables/Renderable.h"

class Plane : public Renderable {
private:
    Vector3F m_Normal;
public:
    Plane(Vector3F & normal);
    Vector3F getNormal(const Vector3F& hitPosition);
    float intersect(const Ray& ray);
};