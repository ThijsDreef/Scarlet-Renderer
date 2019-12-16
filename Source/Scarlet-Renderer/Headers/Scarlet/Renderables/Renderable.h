#pragma once
#include "Scarlet/Math/Vector3F.h"
#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Math/Mat4x4.h"

class Renderable {
private:
    void recalcTransform();
protected: 
    Mat4x4 m_InverseTransform;
    Vector3F m_Translation;
    Vector3F m_Rotation;
public:
    Mat4x4 m_Transform;
    Ray transformRay(const Ray& ray);
    void translate(Vector3F translation);
    void rotate(Vector3F rotate);
    unsigned int m_materialId;
    virtual Vector3F getNormal(const Vector3F& ray) = 0;
    virtual float intersect(const Ray& ray) = 0;
};