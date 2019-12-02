#include "Scarlet/Math/Vector3F.h"

class Mat4x4 {
private:
    float m_Matrix[16];
public:
    void translate(const Vector3F& translation);
    void rotate(int axis, float radians);
    void rotate(const Vector3F& rotation);
    void Scale(const Vector3F& scale);
    Mat4x4();
    ~Mat4x4();
};