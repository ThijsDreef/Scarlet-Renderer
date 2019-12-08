#include "Scarlet/Math/Vector3F.h"

class Mat4x4 {
private:
    float m_Matrix[16];
public:
    void identity();
    void translate(const Vector3F& translation);
    void rotateX(float radians);
    void rotateY(float radians);
    void rotateZ(float radians);

    void rotate(const Vector3F& rotation);
    void scale(const Vector3F& scale);

    void rotateBy(const Vector3F& rotation);
    void translateBy(const Vector3F& translation);
    void scaleBy(const Vector3F& scale);


    void operator*=(const Mat4x4& other);
    Mat4x4 operator*(const Mat4x4& other);
    Vector3F operator*(const Vector3F& other);

    Mat4x4();
    ~Mat4x4();
};