#include "Scarlet/Camera.h"
#define _USE_MATH_DEFINES
#include <math.h>

Camera::Camera(Vector3F lens, unsigned int fov) {
    m_Lens = lens;
    m_Fov = fov;
}

Camera::~Camera() {

}

std::vector<Ray> Camera::calculateRays(unsigned int w, unsigned int h, unsigned int pd) {
    std::vector<Ray> cameraRays;
    
    Vector3F eye = m_Lens.unit() - Vector3F(0, 0, 0);
    
    Vector3F right = eye.cross(Vector3F(0, 1, 0));
    Vector3F up = right.cross(eye);

    float fovRadians = M_PI * (m_Fov / 2.0) / 180.0;
    float hwr = (float)h/w;
    float hw = tan(fovRadians);
    float hh = hwr * hw;
    float cw = hw * 2;
    float ch = hh * 2;
    float pw = cw / (w - 1);
    float ph = ch / (h - 1);

    for (unsigned int y = 0; y < h; y++) {
        for (unsigned int x = 0; x < w; x++) {
            for (unsigned int p = 0; p < pd; p++) {
                float scaleFactorX = (static_cast<float>(p) / pd - 0.5) * 2.0f;
                float scaleFactorY = (static_cast<float>(p) / pd - 0.5) * 2.0f;

                Vector3F xVector = right * ((x + scaleFactorX) * pw - hw);
                Vector3F yVector = up * ((y + scaleFactorY) * ph - hh);
                cameraRays.push_back(Ray(Vector3F(0, 0, 0), (eye + xVector + yVector).unit()));
            }
        }
    }

    return cameraRays;
}
