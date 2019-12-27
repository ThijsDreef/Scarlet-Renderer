#pragma once
#include "Scarlet/AccelerationStructures/AccelerationStructure.h"
#include "Scarlet/Objects/Color.h"
#include "Scarlet/Materials/MaterialLibrary.h"

class Scene {  
private:
    AccelerationStructure* m_AccelerationStructure;
    MaterialLibrary m_MaterialLibrary;
    std::vector<Renderable*> m_Renderables;
public:
    void addObject(Renderable* object);
    unsigned int addMaterial(Material* material);
    Renderable* getObject(const Ray& ray) const;
    Material* getMaterial(unsigned int id) const;
    Scene(AccelerationStructure* accelerationStructure);
    ~Scene();
};