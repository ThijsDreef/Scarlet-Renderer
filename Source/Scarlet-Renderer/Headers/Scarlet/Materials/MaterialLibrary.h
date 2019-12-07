#include "Scarlet/Materials/Material.h"

class MaterialLibrary
{
private:
    std::vector<Material*> m_Materials;
public:
    unsigned int addMaterial(Material* material);
    Material* getMaterial(unsigned int id);
    MaterialLibrary();
    ~MaterialLibrary();
};