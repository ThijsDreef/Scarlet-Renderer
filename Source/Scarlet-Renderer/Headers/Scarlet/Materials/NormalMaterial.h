#pragma once
#include "Scarlet/Materials/Material.h"

class NormalMaterial : public Material {
public:
    Color getMaterialColor(Renderable* r, const Vector3F& hit);
};