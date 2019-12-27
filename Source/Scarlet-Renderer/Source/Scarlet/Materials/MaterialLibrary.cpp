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
    if (id > 0) {
        id = m_FreeList[id];
        m_FreeList.pop_back();
    } else {
        id = m_Materials.size();
    }
    return id;
}

unsigned int MaterialLibrary::addMaterial(Material* u_Material) {
    unsigned int id = getNewId();
    if (id >= m_Materials.size()) {
        m_Materials.push_back(u_Material);
    } else {
        m_Materials[id] = u_Material;
    }
    return id;
}

void MaterialLibrary::deleteMaterial(unsigned int id) {
    if (id == 0 || id > m_Materials.size()) return;
    m_FreeList.push_back(id);
    delete m_Materials[id];
    m_Materials[id] = 0;
}

Material* MaterialLibrary::getMaterial(unsigned int id) const {
    return (m_Materials.size() > id) ? m_Materials[id] : m_Materials[0];
}