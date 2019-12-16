#include "Scarlet/Renderables/Sphere.h"
#include <cmath>
#include <iostream>

Sphere::Sphere(float radius) {
    m_Radius = radius;
}

Vector3F Sphere::getNormal(const Vector3F& hitPosition) {
	
    Vector3F normal = m_Translation - hitPosition;
	normal.normalize();
	// std::cout << "hit" << hitPosition.x << " " << hitPosition.y << " " << hitPosition.z << "\n";
	// std::cout << "pos" << m_Translation.x << " " << m_Translation.y << " " << m_Translation.z << "\n";
	// std::cout << "norm" << normal.x << " " << normal.y << " " << normal.z << "\n";
    return normal.unit();

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
	std::cout << t1 << "\n";
	return t1;
}