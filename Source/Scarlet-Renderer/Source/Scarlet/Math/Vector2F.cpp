#include "Scarlet/Math/Vector2F.h"
#include <cmath>

Vector2F::Vector2F() {
    this->x = 0;
    this->y = 0;
}

Vector2F::Vector2F(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2F::~Vector2F() {

}

void Vector2F::normalize() {
    *this /= length();
}

Vector2F Vector2F::unit() {
    return *this / length();
}

float Vector2F::length() {
    return sqrtf(x * x + y * y);
}

float Vector2F::dot(Vector2F other) {
    return (x * other.x + y * other.y);
}

Vector2F Vector2F::operator*(float scalar) {
    return Vector2F(x * scalar, y * scalar);
}

Vector2F Vector2F::operator/(float scalar) {
    return Vector2F(x / scalar, y / scalar);
}

Vector2F Vector2F::operator+(float add) {
    return Vector2F(x + add, y + add);
}

Vector2F Vector2F::operator-(float min) {
    return Vector2F(x - min, y - min);
}

Vector2F Vector2F::operator*(Vector2F scalar) {
    return Vector2F(x * scalar.x, y * scalar.y);
}

Vector2F Vector2F::operator/(Vector2F scalar) {
    return Vector2F(x / scalar.x, y / scalar.y);
}

Vector2F Vector2F::operator+(Vector2F add) {
    return Vector2F(x + add.x, y + add.y);
}

Vector2F Vector2F::operator-(Vector2F min) {
    return Vector2F(x - min.x, y - min.y);
}

Vector2F Vector2F::operator-() {
    return Vector2F(-x, -y);
}

void Vector2F::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
}

void Vector2F::operator*=(Vector2F other) {
    x *= other.x;
    y *= other.y;
}

void Vector2F::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
}

void Vector2F::operator/=(Vector2F other) {
    x /= other.x;
    y /= other.y;
}

void Vector2F::operator+=(float add) {
    x += add;
    y += add;
}

void Vector2F::operator+=(Vector2F other) {
    x += other.x;
    y += other.y;
}

void Vector2F::operator-=(float min) {
    x -= min;
    y -= min;
}

void Vector2F::operator-=(Vector2F other) {
    x -= other.x;
    y -= other.y;
}