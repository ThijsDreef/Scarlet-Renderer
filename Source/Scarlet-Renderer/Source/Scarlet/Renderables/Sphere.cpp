#include "Scarlet/Renderables/Sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere(float radius) {
    m_Radius = radius;
}

Vector3F Sphere::getNormal(const Vector3F& hitPosition) {
    return -hitPosition.unit();
}

float Sphere::intersect(const Ray& ray) {
	Ray transformed = transformRay(ray);
	float tca = transformed.origin.dot(transformed.direction); 
	if (tca < 0) return -1; 
	float d2 = transformed.origin.dot(transformed.origin) - tca * tca; 
	if (d2 > (m_Radius * m_Radius)) return -1; 
	float thc = sqrt((m_Radius * m_Radius) - d2);
	float t1 = tca - thc;
	float t2 = tca + thc;
	if (t1 > t2) {
		float temp = t2;
		t2 = t1;
		t1 = temp;
	}

	if (t1 < 0) {
		t1 = t2; 
		if (t1 < 0) return -1; 
	}

	return t1;
}