#pragma once

class Vector3F {
public:
    float x, y, z;

    float length() const;
    float dot(Vector3F other) const;
    void normalize();
    Vector3F unit() const;
    Vector3F cross(Vector3F other) const;

    Vector3F operator-() const;
    Vector3F operator/(Vector3F scalar) const;
    void operator/=(Vector3F scalar);
    Vector3F operator+(Vector3F add) const;
    void operator+=(Vector3F add);
    Vector3F operator-(Vector3F min) const;
    void operator-=(Vector3F min);
    Vector3F operator*(Vector3F scalar) const;
    void operator*=(Vector3F scalar);

    Vector3F operator/(float scalar) const;
    void operator/=(float scalar);   
    Vector3F operator+(float add) const;
    void operator+=(float add);
    Vector3F operator-(float min) const;
    void operator-=(float min);
    Vector3F operator*(float scalar) const;
    void operator*=(float scalar);

    Vector3F();
    Vector3F(float x, float y, float z);
    ~Vector3F();
};