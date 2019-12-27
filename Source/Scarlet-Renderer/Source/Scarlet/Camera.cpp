#include "Scarlet/Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>

Camera::Camera(Vector3F lens, unsigned int fov) {
    m_Lens = lens;
    m_Fov = fov;
}

Camera::~Camera() {

}

Ray Camera::getRayByIndex(unsigned int i, unsigned int aa) const {
    unsigned int x = i % m_w;
    unsigned int y = i / m_h;
    
    float scaleFactorX = (static_cast<float>(aa) / m_pd - 0.5f) * 1.5f;
    float scaleFactorY = (static_cast<float>(aa) / m_pd - 0.5f) * 1.5f;

    Vector3F xVector = right * ((x + scaleFactorX) * m_pw - m_hw);
    Vector3F yVector = up * ((y + scaleFactorY) * m_ph - m_hh);
    return Ray(Vector3F(0, 0, 0), (eye + xVector + yVector).unit());
}

unsigned int Camera::calculateRays(unsigned int w, unsigned int h, unsigned int pd) {
    m_pd = pd;
    m_w = w;
    m_h = h;

    eye = m_Lens.unit() - Vector3F(0, 0, 0);
    
    right = eye.cross(Vector3F(0, 1, 0));
    up = right.cross(eye);

    float fovRadians = M_PI * (m_Fov / 2.0f) / 180.0f;
    float hwr = static_cast<float>(m_h)/m_w;
    m_hw = tanf(fovRadians);
    m_hh = hwr * m_hw;
    float cw = m_hw * 2;
    float ch = m_hh * 2;
    m_pw = cw / (m_w - 1);
    m_ph = ch / (m_h - 1);

    return m_w * m_h * pd;
}

unsigned int Camera::calculateRays(unsigned int w, unsigned int h, unsigned int pd, std::vector<Ray> & cameraRays) const {
    
    Vector3F eye = m_Lens.unit() - Vector3F(0, 0, 0);
    
    Vector3F right = eye.cross(Vector3F(0, 1, 0));
    Vector3F up = right.cross(eye);

    float fovRadians = M_PI * (m_Fov / 2.0f) / 180.0f;
    float hwr = (float)h/w;
    float hw = tanf(fovRadians);
    float hh = hwr * hw;
    float cw = hw * 2;
    float ch = hh * 2;
    float pw = cw / (w - 1);
    float ph = ch / (h - 1);

    for (unsigned int y = 0; y < h; y++) {
        for (unsigned int x = 0; x < w; x++) {
            for (unsigned int p = 0; p < pd; p++) {
                float scaleFactorX = (static_cast<float>(p) / pd - 0.5f) * 1.5f;
                float scaleFactorY = (static_cast<float>(p) / pd - 0.5f) * 1.5f;

                Vector3F xVector = right * ((x + scaleFactorX) * pw - hw);
                Vector3F yVector = up * ((y + scaleFactorY) * ph - hh);
                cameraRays.push_back(Ray(Vector3F(0, 0, 0), (eye + xVector + yVector).unit()));
            }
        }
    }

    return static_cast<unsigned int>(cameraRays.size());
}
