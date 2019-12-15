#include "Scarlet/Materials/NormalMaterial.h"

Color NormalMaterial::getMaterialColor(Renderable* r, const Vector3F& hit) {
    Vector3F normal = r->getNormal(hit);
    return Color(normal.x, normal.y, normal.z);
}