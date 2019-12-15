#pragma once
#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Math/Mat4x4.h"
#include <vector>


class Camera {
private:
    Vector3F m_Lens;
    unsigned int m_Fov;
public:
    Mat4x4 m_Transform;
    std::vector<Ray> calculateRays(unsigned int w, unsigned int h);
    Camera(Vector3F lens, unsigned int fov);
    ~Camera();
};