#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Objects/Color.h"

struct Material {
    Color diffuseColor;
    Color specularColor;
    bool reflective;
    float refractionIndex;
};