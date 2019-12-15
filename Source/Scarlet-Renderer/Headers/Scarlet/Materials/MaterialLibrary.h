#pragma once
#include "Scarlet/Materials/Material.h"
#include <vector>

class MaterialLibrary
{
private:
    std::vector<Material*> m_Materials;
    std::vector<unsigned int> m_FreeList;
    unsigned int getNewId();
public:
    unsigned int addMaterial(Material* u_Material);
    Material* getMaterial(unsigned int id);
    void deleteMaterial(unsigned int id);
    MaterialLibrary();
    ~MaterialLibrary();
};