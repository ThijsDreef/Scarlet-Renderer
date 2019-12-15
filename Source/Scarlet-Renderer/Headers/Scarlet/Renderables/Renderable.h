#pragma once
#include "Scarlet/Math/Vector3F.h"
#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Math/Mat4x4.h"

class Renderable {
public:
    unsigned int m_materialId;
    Mat4x4 m_transform;
    virtual Vector3F getNormal(const Vector3F& hitPosition) = 0;
    virtual float intersect(const Ray& ray) = 0;
};