#include "Scarlet/Objects/Ray.h"
#include "Scarlet/Objects/Color.h"
#include "Scarlet/Renderables/Renderable.h"

class Material {
public:
    float m_RefractionIndex;
    float m_ReflectiveStrength;
    bool m_Reflective;
    virtual Color getMaterialColor(const Renderable * r, const Vector3F& hit) = 0;
};