#pragma once
#include "Scarlet/Math/Vector3F.h"

class Ray {
public:
    Vector3F origin;
    Vector3F direction;
    Ray();
    Ray(Vector3F origin, Vector3F direction);
};