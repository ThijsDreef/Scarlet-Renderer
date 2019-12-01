#include "Scarlet/Objects/Ray.h"

Ray::Ray() {
    origin = Vector3F(0, 0, 0);
    direction = Vector3F(0, 0, 1);
}

Ray::Ray(Vector3F origin, Vector3F direction) {
    this->origin = origin;
    this->direction = direction;
}