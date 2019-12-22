#include "Scarlet/Materials/Material.h"

class ColorMaterial : public Material {
private:
    Color m_Color;
public:
    ColorMaterial(const Color& color);
    ~ColorMaterial();
    Color getMaterialColor(Renderable* r, const Vector3F& hit);
};