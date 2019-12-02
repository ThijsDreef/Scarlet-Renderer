#include "Scarlet/Math/Vector3F.h"

Vector3F::Vector3F() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3F::Vector3F(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3F::~Vector3F() {

}

Vector3F Vector3F::cross(Vector3F other) {
    return Vector3F((y * other.z) - (z * other.y), (z * other.x) - (x * other.z), (x * other.y) - (y * other.x));
}

void Vector3F::normalize() {
    *this /= length();
}

Vector3F Vector3F::unit() {
    return *this / length();
}

float Vector3F::length() {
    return sqrtf(x * x + y * y + z * z);
}

float Vector3F::dot(Vector3F other) {
    return (x * other.x + y * other.y + z * other.z);
}

Vector3F Vector3F::operator*(float scalar) {
    return Vector3F(x * scalar, y * scalar, z * scalar);
}

Vector3F Vector3F::operator/(float scalar) {
    return Vector3F(x / scalar, y / scalar, z / scalar);
}

Vector3F Vector3F::operator+(float add) {
    return Vector3F(x + add, y + add, z + add);
}

Vector3F Vector3F::operator-(float min) {
    return Vector3F(x - min, y - min, z - min);
}

Vector3F Vector3F::operator*(Vector3F scalar) {
    return Vector3F(x * scalar.x, y * scalar.y, z * scalar.z);
}

Vector3F Vector3F::operator/(Vector3F scalar) {
    return Vector3F(x / scalar.x, y / scalar.y, z / scalar.z);
}

Vector3F Vector3F::operator+(Vector3F add) {
    return Vector3F(x + add.x, y + add.y, z + add.z);
}

Vector3F Vector3F::operator-(Vector3F min) {
    return Vector3F(x - min.x, y - min.y, z - min.z);
}

Vector3F Vector3F::operator-() {
    return Vector3F(-x, -y, -z);
}

void Vector3F::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void Vector3F::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
}

void Vector3F::operator+=(float add) {
    x += add;
    y += add;
    z += add;
}

void Vector3F::operator-=(float min) {
    x -= min;
    y -= min;
    z -= min;
}