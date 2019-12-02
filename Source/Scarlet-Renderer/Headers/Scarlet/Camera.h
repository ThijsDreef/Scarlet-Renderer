#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Math/Mat4x4.h"
#include <vector>

class Camera {
private:
    Vector3F m_eye;
    unsigned int m_fov;
public:
    Mat4x4 m_Rotation;
    Mat4x4 m_Translation;
    std::vector<Ray> calculateRays(unsigned int w, unsigned int h);
    Camera(Vector3F eye, unsigned int fov);
    ~Camera();
};