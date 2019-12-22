#include "Scarlet/Materials/ColorMaterial.h"

ColorMaterial::ColorMaterial(const Color & color) {
    m_Color = color;
}

ColorMaterial::~ColorMaterial() {

}

Color ColorMaterial::getMaterialColor(Renderable* r, const Vector3F& hit) {
    return m_Color;
}