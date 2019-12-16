#pragma once

class Vector2F {
public:
    float x, y;

    float length();
    float dot(Vector2F other);
    void normalize();
    Vector2F unit();

    Vector2F operator-();
    Vector2F operator/(Vector2F scalar);
    void operator/=(Vector2F scalar);
    Vector2F operator+(Vector2F add);
    void operator+=(Vector2F add);
    Vector2F operator-(Vector2F min);
    void operator-=(Vector2F min);
    Vector2F operator*(Vector2F scalar);
    void operator*=(Vector2F scalar);

    Vector2F operator/(float scalar);
    void operator/=(float scalar);   
    Vector2F operator+(float add);
    void operator+=(float add);
    Vector2F operator-(float min);
    void operator-=(float min);
    Vector2F operator*(float scalar);
    void operator*=(float scalar);

    Vector2F();
    Vector2F(float x, float y);
    ~Vector2F();
};