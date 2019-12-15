#include "Scarlet/Materials/MaterialLibrary.h"

MaterialLibrary::MaterialLibrary() {

}

MaterialLibrary::~MaterialLibrary() {
    for (unsigned int i = 0; i < m_Materials.size(); i++) {
        if (m_Materials[i]) delete m_Materials[i];
    }
}

unsigned int MaterialLibrary::getNewId() {
    unsigned int id = m_FreeList.size();
    id = (id > 0) ? m_FreeList[id] : m_Materials.size();
    return id;
}

unsigned int MaterialLibrary::addMaterial(Material* u_Material) {
    unsigned int id = getNewId();
    if (id > m_Materials.size()) {
        m_Materials.push_back(u_Material);
    } else {
        m_Materials[id] = u_Material;
    }
    return id;
}

void MaterialLibrary::deleteMaterial(unsigned int id) {
    if (id == 0) return;
    m_FreeList.push_back(id);
    delete m_Materials[id];
    m_Materials[id] = 0;
}

Material* MaterialLibrary::getMaterial(unsigned int id) {
    Material* m = m_Materials[id];
    return (m) ? m : m_Materials[0];
}