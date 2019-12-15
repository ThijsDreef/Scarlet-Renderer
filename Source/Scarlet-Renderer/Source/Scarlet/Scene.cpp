#include "Scarlet/Scene.h"

Scene::Scene(AccelerationStructure* accelerationStructure) {
    m_AccelerationStructure = accelerationStructure;
}

Scene::~Scene() {
    
}

void Scene::addObject(Renderable* object) {
    m_Renderables.push_back(object);
}

unsigned int Scene::addMaterial(Material* material) {
    return m_MaterialLibrary.addMaterial(material);
}

Renderable* Scene::getObject(const Ray& ray) {
    return m_AccelerationStructure->getObject(ray);
}

Material* Scene::getMaterial(unsigned int id) {
    return m_MaterialLibrary.getMaterial(id);
}