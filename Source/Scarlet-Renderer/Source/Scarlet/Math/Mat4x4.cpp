#include "Scarlet/Math/Mat4x4.h"
#include <cmath>

Mat4x4::Mat4x4() {
    identity();
}

Mat4x4::~Mat4x4() {

}

void Mat4x4::identity() {
    for (unsigned int i = 0; i < 16; i++) {
        m_Matrix[i] = 0;
    }
    m_Matrix[0] = 1;
    m_Matrix[5] = 1;
    m_Matrix[10] = 1;
    m_Matrix[15] = 1;
}


void Mat4x4::translate(const Vector3F& translation) {
    identity();
    m_Matrix[12] = translation.x;
    m_Matrix[13] = translation.y;
    m_Matrix[14] = translation.z;
}

void Mat4x4::translateBy(const Vector3F& tranlation) {
    Mat4x4 multBy;
    multBy.translate(tranlation);
    *this = multBy * *this;
}

void Mat4x4::rotateX(float radians) {
    identity();
    m_Matrix[5] = cos(radians);
    m_Matrix[6] = -sin(radians);
    m_Matrix[9] = sin(radians);
    m_Matrix[10] = cos(radians);
}

void Mat4x4::rotateY(float radians) {
    identity();
    m_Matrix[0] = cos(radians);
    m_Matrix[2] = sin(radians);
    m_Matrix[8] = -sin(radians);
    m_Matrix[10] = cos(radians);
}

void Mat4x4::rotateZ(float radians) {
    identity();
    m_Matrix[0] = cos(radians);
    m_Matrix[1] = -sin(radians);
    m_Matrix[4] = sin(radians);
    m_Matrix[5] = cos(radians);
}

void Mat4x4::rotate(const Vector3F& rotation) {
    Mat4x4 rot;
    identity();
    rot.rotateX(rotation.x);
    *this = rot * *this;
    rot.rotateY(rotation.y);
    *this = rot * *this;
    rot.rotateZ(rotation.z);
    *this = rot * *this;
}

void Mat4x4::rotateBy(const Vector3F& rotation) {
    Mat4x4 rot;
    rot.rotateX(rotation.x);
    *this = rot * *this;
    rot.rotateY(rotation.y);
    *this = rot * *this;
    rot.rotateZ(rotation.z);
    *this = rot * *this;
}

void Mat4x4::scale(const Vector3F& scale) {
    identity();
    m_Matrix[0] = scale.x;
    m_Matrix[5] = scale.y;
    m_Matrix[10] = scale.z;
}

void Mat4x4::scaleBy(const Vector3F& scale) {
    Mat4x4 s;
    s.scale(scale);
    *this = s * *this;
}

void Mat4x4::operator*=(const Mat4x4& other) {
    *this = *this * other;
}

Mat4x4 Mat4x4::operator*(const Mat4x4& other) {
    Mat4x4 temp;
	
	temp.m_Matrix[0] = m_Matrix[0] * other.m_Matrix[0] + m_Matrix[4] * other.m_Matrix[1] + m_Matrix[8] * other.m_Matrix[2] + m_Matrix[12] * other.m_Matrix[3];
	temp.m_Matrix[1] = m_Matrix[1] * other.m_Matrix[0] + m_Matrix[5] * other.m_Matrix[1] + m_Matrix[9] * other.m_Matrix[2] + m_Matrix[13] * other.m_Matrix[3];
	temp.m_Matrix[2] = m_Matrix[2] * other.m_Matrix[0] + m_Matrix[6] * other.m_Matrix[1] + m_Matrix[10] * other.m_Matrix[2] + m_Matrix[14] * other.m_Matrix[3];
	temp.m_Matrix[3] = m_Matrix[3] * other.m_Matrix[0] + m_Matrix[7] * other.m_Matrix[1] + m_Matrix[11] * other.m_Matrix[2] + m_Matrix[15] * other.m_Matrix[3];

	temp.m_Matrix[4] = m_Matrix[0] * other.m_Matrix[4] + m_Matrix[4] * other.m_Matrix[5] + m_Matrix[8] * other.m_Matrix[6] + m_Matrix[12] * other.m_Matrix[7];
	temp.m_Matrix[5] = m_Matrix[1] * other.m_Matrix[4] + m_Matrix[5] * other.m_Matrix[5] + m_Matrix[9] * other.m_Matrix[6] + m_Matrix[13] * other.m_Matrix[7];
	temp.m_Matrix[6] = m_Matrix[2] * other.m_Matrix[4] + m_Matrix[6] * other.m_Matrix[5] + m_Matrix[10] * other.m_Matrix[6] + m_Matrix[14] * other.m_Matrix[7];
	temp.m_Matrix[7] = m_Matrix[3] * other.m_Matrix[4] + m_Matrix[7] * other.m_Matrix[5] + m_Matrix[11] * other.m_Matrix[6] + m_Matrix[15] * other.m_Matrix[7];

	temp.m_Matrix[8] = m_Matrix[0] * other.m_Matrix[8] + m_Matrix[4] * other.m_Matrix[9] + m_Matrix[8] * other.m_Matrix[10] + m_Matrix[12] * other.m_Matrix[11];
	temp.m_Matrix[9] = m_Matrix[1] * other.m_Matrix[8] + m_Matrix[5] * other.m_Matrix[9] + m_Matrix[9] * other.m_Matrix[10] + m_Matrix[13] * other.m_Matrix[11];
	temp.m_Matrix[10] = m_Matrix[2] * other.m_Matrix[8] + m_Matrix[6] * other.m_Matrix[9] + m_Matrix[10] * other.m_Matrix[10] + m_Matrix[14] * other.m_Matrix[11];
	temp.m_Matrix[11] = m_Matrix[3] * other.m_Matrix[8] + m_Matrix[7] * other.m_Matrix[9] + m_Matrix[11] * other.m_Matrix[10] + m_Matrix[15] * other.m_Matrix[11];

	temp.m_Matrix[12] = m_Matrix[0] * other.m_Matrix[12] + m_Matrix[4] * other.m_Matrix[13] + m_Matrix[8] * other.m_Matrix[14] + m_Matrix[12] * other.m_Matrix[15];
	temp.m_Matrix[13] = m_Matrix[1] * other.m_Matrix[12] + m_Matrix[5] * other.m_Matrix[13] + m_Matrix[9] * other.m_Matrix[14] + m_Matrix[13] * other.m_Matrix[15];
	temp.m_Matrix[14] = m_Matrix[2] * other.m_Matrix[12] + m_Matrix[6] * other.m_Matrix[13] + m_Matrix[10] * other.m_Matrix[14] + m_Matrix[14] * other.m_Matrix[15];
	temp.m_Matrix[15] = m_Matrix[3] * other.m_Matrix[12] + m_Matrix[7] * other.m_Matrix[13] + m_Matrix[11] * other.m_Matrix[14] + m_Matrix[15] * other.m_Matrix[15];

	return temp;
}

Vector3F Mat4x4::multByVector(const Vector3F& other) {
    Vector3F t;
	t.x = other.x * m_Matrix[0] + other.y * m_Matrix[4] + other.z * m_Matrix[8] + m_Matrix[12];
	t.y = other.x * m_Matrix[1] + other.y * m_Matrix[5] + other.z * m_Matrix[9] + m_Matrix[13];
	t.z = other.x * m_Matrix[2] + other.y * m_Matrix[6] + other.z * m_Matrix[10] + m_Matrix[14];
	return t;
}

Vector3F Mat4x4::multDirection(const Vector3F& direction) {
    Vector3F t;
	t.x = direction.x * m_Matrix[0] + direction.y * m_Matrix[4] + direction.z * m_Matrix[8];
	t.y = direction.x * m_Matrix[1] + direction.y * m_Matrix[5] + direction.z * m_Matrix[9];
	t.z = direction.x * m_Matrix[2] + direction.y * m_Matrix[6] + direction.z * m_Matrix[10];
	return t;
}

Mat4x4 Mat4x4::inverse() {
    double det;
	Mat4x4 inv;
  	int i;

  	inv.m_Matrix[0] = m_Matrix[5]  * m_Matrix[10] * m_Matrix[15] - m_Matrix[5]  * m_Matrix[11] * m_Matrix[14] - m_Matrix[9]  * m_Matrix[6]  * m_Matrix[15] +m_Matrix[9]  * m_Matrix[7]  * m_Matrix[14] +m_Matrix[13] * m_Matrix[6]  * m_Matrix[11] -m_Matrix[13] * m_Matrix[7]  * m_Matrix[10];

    inv.m_Matrix[4] = -m_Matrix[4]  * m_Matrix[10] * m_Matrix[15] + m_Matrix[4]  * m_Matrix[11] * m_Matrix[14] +m_Matrix[8]  * m_Matrix[6]  * m_Matrix[15] - m_Matrix[8]  * m_Matrix[7]  * m_Matrix[14] - m_Matrix[12] * m_Matrix[6]  * m_Matrix[11] + m_Matrix[12] * m_Matrix[7]  * m_Matrix[10];

    inv.m_Matrix[8] = m_Matrix[4]  * m_Matrix[9] * m_Matrix[15] - m_Matrix[4]  * m_Matrix[11] * m_Matrix[13] -m_Matrix[8]  * m_Matrix[5] * m_Matrix[15] +m_Matrix[8]  * m_Matrix[7] * m_Matrix[13] +m_Matrix[12] * m_Matrix[5] * m_Matrix[11] -m_Matrix[12] * m_Matrix[7] * m_Matrix[9];

    inv.m_Matrix[12] = -m_Matrix[4]  * m_Matrix[9] * m_Matrix[14] + m_Matrix[4]  * m_Matrix[10] * m_Matrix[13] + m_Matrix[8]  * m_Matrix[5] * m_Matrix[14] -  m_Matrix[8]  * m_Matrix[6] * m_Matrix[13] -  m_Matrix[12] * m_Matrix[5] * m_Matrix[10] +  m_Matrix[12] * m_Matrix[6] * m_Matrix[9];

    inv.m_Matrix[1] = -m_Matrix[1]  * m_Matrix[10] * m_Matrix[15] + m_Matrix[1]  * m_Matrix[11] * m_Matrix[14] +m_Matrix[9]  * m_Matrix[2] * m_Matrix[15] - m_Matrix[9]  * m_Matrix[3] * m_Matrix[14] - m_Matrix[13] * m_Matrix[2] * m_Matrix[11] + m_Matrix[13] * m_Matrix[3] * m_Matrix[10];

    inv.m_Matrix[5] = m_Matrix[0]  * m_Matrix[10] * m_Matrix[15] - m_Matrix[0]  * m_Matrix[11] * m_Matrix[14] -m_Matrix[8]  * m_Matrix[2] * m_Matrix[15] +m_Matrix[8]  * m_Matrix[3] * m_Matrix[14] +m_Matrix[12] * m_Matrix[2] * m_Matrix[11] -m_Matrix[12] * m_Matrix[3] * m_Matrix[10];

    inv.m_Matrix[9] = -m_Matrix[0]  * m_Matrix[9] * m_Matrix[15] + m_Matrix[0]  * m_Matrix[11] * m_Matrix[13] +m_Matrix[8]  * m_Matrix[1] * m_Matrix[15] - m_Matrix[8]  * m_Matrix[3] * m_Matrix[13] - m_Matrix[12] * m_Matrix[1] * m_Matrix[11] + m_Matrix[12] * m_Matrix[3] * m_Matrix[9];

    inv.m_Matrix[13] = m_Matrix[0]  * m_Matrix[9] * m_Matrix[14] - m_Matrix[0]  * m_Matrix[10] * m_Matrix[13] -m_Matrix[8]  * m_Matrix[1] * m_Matrix[14] + m_Matrix[8]  * m_Matrix[2] * m_Matrix[13] + m_Matrix[12] * m_Matrix[1] * m_Matrix[10] - m_Matrix[12] * m_Matrix[2] * m_Matrix[9];

    inv.m_Matrix[2] = m_Matrix[1]  * m_Matrix[6] * m_Matrix[15] - m_Matrix[1]  * m_Matrix[7] * m_Matrix[14] -m_Matrix[5]  * m_Matrix[2] * m_Matrix[15] +m_Matrix[5]  * m_Matrix[3] * m_Matrix[14] +m_Matrix[13] * m_Matrix[2] * m_Matrix[7] -m_Matrix[13] * m_Matrix[3] * m_Matrix[6];

    inv.m_Matrix[6] = -m_Matrix[0]  * m_Matrix[6] * m_Matrix[15] + m_Matrix[0]  * m_Matrix[7] * m_Matrix[14] +m_Matrix[4]  * m_Matrix[2] * m_Matrix[15] - m_Matrix[4]  * m_Matrix[3] * m_Matrix[14] - m_Matrix[12] * m_Matrix[2] * m_Matrix[7] + m_Matrix[12] * m_Matrix[3] * m_Matrix[6];

    inv.m_Matrix[10] = m_Matrix[0]  * m_Matrix[5] * m_Matrix[15] - m_Matrix[0]  * m_Matrix[7] * m_Matrix[13] -m_Matrix[4]  * m_Matrix[1] * m_Matrix[15] + m_Matrix[4]  * m_Matrix[3] * m_Matrix[13] + m_Matrix[12] * m_Matrix[1] * m_Matrix[7] - m_Matrix[12] * m_Matrix[3] * m_Matrix[5];

    inv.m_Matrix[14] = -m_Matrix[0]  * m_Matrix[5] * m_Matrix[14] + m_Matrix[0]  * m_Matrix[6] * m_Matrix[13] + m_Matrix[4]  * m_Matrix[1] * m_Matrix[14] -  m_Matrix[4]  * m_Matrix[2] * m_Matrix[13] -  m_Matrix[12] * m_Matrix[1] * m_Matrix[6] +  m_Matrix[12] * m_Matrix[2] * m_Matrix[5];

    inv.m_Matrix[3] = -m_Matrix[1] * m_Matrix[6] * m_Matrix[11] + m_Matrix[1] * m_Matrix[7] * m_Matrix[10] +m_Matrix[5] * m_Matrix[2] * m_Matrix[11] - m_Matrix[5] * m_Matrix[3] * m_Matrix[10] - m_Matrix[9] * m_Matrix[2] * m_Matrix[7] + m_Matrix[9] * m_Matrix[3] * m_Matrix[6];

    inv.m_Matrix[7] = m_Matrix[0] * m_Matrix[6] * m_Matrix[11] - m_Matrix[0] * m_Matrix[7] * m_Matrix[10] -m_Matrix[4] * m_Matrix[2] * m_Matrix[11] +m_Matrix[4] * m_Matrix[3] * m_Matrix[10] +m_Matrix[8] * m_Matrix[2] * m_Matrix[7] -m_Matrix[8] * m_Matrix[3] * m_Matrix[6];

    inv.m_Matrix[11] = -m_Matrix[0] * m_Matrix[5] * m_Matrix[11] + m_Matrix[0] * m_Matrix[7] * m_Matrix[9] + m_Matrix[4] * m_Matrix[1] * m_Matrix[11] -  m_Matrix[4] * m_Matrix[3] * m_Matrix[9] -  m_Matrix[8] * m_Matrix[1] * m_Matrix[7] +  m_Matrix[8] * m_Matrix[3] * m_Matrix[5];

    inv.m_Matrix[15] = m_Matrix[0] * m_Matrix[5] * m_Matrix[10] - m_Matrix[0] * m_Matrix[6] * m_Matrix[9] -m_Matrix[4] * m_Matrix[1] * m_Matrix[10] + m_Matrix[4] * m_Matrix[2] * m_Matrix[9] + m_Matrix[8] * m_Matrix[1] * m_Matrix[6] - m_Matrix[8] * m_Matrix[2] * m_Matrix[5];

    det = m_Matrix[0] * inv.m_Matrix[0] + m_Matrix[1] * inv.m_Matrix[4] + m_Matrix[2] * inv.m_Matrix[8] + m_Matrix[3] * inv.m_Matrix[12];

    if (det == 0) {
        inv.identity();
        return inv;
    }

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        inv.m_Matrix[i] *= det;
    
    return inv;
}