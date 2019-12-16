#pragma once
#include "Scarlet/Renderables/Renderable.h"

class Sphere: public Renderable {
private:
    float m_Radius;
public:
    Sphere(float radius);
    Vector3F getNormal(const Vector3F& hitPosition);
    float intersect(const Ray& ray);
};