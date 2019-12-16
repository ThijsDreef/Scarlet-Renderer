#include "Scarlet/Math/Vector4F.h"
#include <cmath>

Vector4F::Vector4F() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Vector4F::Vector4F(float x, float y, float z, float w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vector4F::~Vector4F() {

}

void Vector4F::normalize() {
    *this /= length();
}

Vector4F Vector4F::unit() {
    return *this / length();
}

float Vector4F::length() {
    return sqrtf(x * x + y * y + z * z + w * w);
}

float Vector4F::dot(Vector4F other) {
    return (x * other.x + y * other.y + z * other.z + other.w * w);
}

Vector4F Vector4F::operator*(float scalar) {
    return Vector4F(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4F Vector4F::operator/(float scalar) {
    return Vector4F(x / scalar, y / scalar, z / scalar, w / scalar);
}

Vector4F Vector4F::operator+(float add) {
    return Vector4F(x + add, y + add, z + add, w + add);
}

Vector4F Vector4F::operator-(float min) {
    return Vector4F(x - min, y - min, z - min, w - min);
}

Vector4F Vector4F::operator*(Vector4F scalar) {
    return Vector4F(x * scalar.x, y * scalar.y, z * scalar.z, w * scalar.w);
}

Vector4F Vector4F::operator/(Vector4F scalar) {
    return Vector4F(x / scalar.x, y / scalar.y, z / scalar.z, w / scalar.w);
}

Vector4F Vector4F::operator+(Vector4F add) {
    return Vector4F(x + add.x, y + add.y, z + add.z, w + add.w);
}

Vector4F Vector4F::operator-(Vector4F min) {
    return Vector4F(x - min.x, y - min.y, z - min.z, w - min.w);
}

Vector4F Vector4F::operator-() {
    return Vector4F(-x, -y, -z, -w);
}

void Vector4F::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
}

void Vector4F::operator*=(Vector4F other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
}

void Vector4F::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
}

void Vector4F::operator/=(Vector4F other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
}

void Vector4F::operator+=(float add) {
    x += add;
    y += add;
    z += add;
    w += add;
}

void Vector4F::operator+=(Vector4F other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

void Vector4F::operator-=(float min) {
    x -= min;
    y -= min;
    z -= min;
    w -= min;
}

void Vector4F::operator-=(Vector4F other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}