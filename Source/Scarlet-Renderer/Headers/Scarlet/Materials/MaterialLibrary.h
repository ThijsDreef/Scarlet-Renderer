#include <map>
#include "Scarlet/Materials/Material.h"

class MaterialLibrary
{
private:
    std::map<unsigned int, Material> m_materials;
public:
    void addMaterial(unsigned int id, Material material);
    Material getMaterial(unsigned int id);
    MaterialLibrary();
    ~MaterialLibrary();
};