#pragma once
#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Math/Mat4x4.h"
#include <vector>


class Camera {
private:
    Vector3F m_Lens;
    unsigned int m_Fov;
    float m_ph;
    float m_pw;
    float m_hh;
    float m_hw;
    unsigned int m_w;
    unsigned int m_h;
    unsigned int m_pd;
    Vector3F eye;
    Vector3F right;
    Vector3F up;
public:
    Mat4x4 m_Transform;
    unsigned int calculateRays(unsigned int w, unsigned int h, unsigned int pd, std::vector<Ray> & cameraRays) const;
    unsigned int calculateRays(unsigned int w, unsigned int h, unsigned int pd);
    Ray getRayByIndex(unsigned int i, unsigned int aa) const;
    Camera(Vector3F lens, unsigned int fov);
    ~Camera();
};