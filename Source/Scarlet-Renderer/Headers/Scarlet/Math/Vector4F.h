#pragma once

class Vector4F {
public:
    float x, y, z, w;

    float length();
    float dot(Vector4F other);
    void normalize();
    Vector4F unit();

    Vector4F operator-();
    Vector4F operator/(Vector4F scalar);
    void operator/=(Vector4F scalar);
    Vector4F operator+(Vector4F add);
    void operator+=(Vector4F add);
    Vector4F operator-(Vector4F min);
    void operator-=(Vector4F min);
    Vector4F operator*(Vector4F scalar);
    void operator*=(Vector4F scalar);

    Vector4F operator/(float scalar);
    void operator/=(float scalar);   
    Vector4F operator+(float add);
    void operator+=(float add);
    Vector4F operator-(float min);
    void operator-=(float min);
    Vector4F operator*(float scalar);
    void operator*=(float scalar);

    Vector4F();
    Vector4F(float x, float y, float z, float w);
    ~Vector4F();
};