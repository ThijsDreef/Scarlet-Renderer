#include "Scarlet/Scene.h"

Scene::Scene(AccelerationStructure* accelerationStructure) {
    m_AccelerationStructure = accelerationStructure;
}

Scene::~Scene() {
    delete m_AccelerationStructure;
}

void Scene::addObject(Renderable* object) {
    m_Renderables.push_back(object);
    m_AccelerationStructure->addObject(object);
}

unsigned int Scene::addMaterial(Material* material) {
    return m_MaterialLibrary.addMaterial(material);
}

Renderable* Scene::getObject(const Ray& ray) const {
    return m_AccelerationStructure->getObject(ray);
}

Material* Scene::getMaterial(unsigned int id) const {
    return m_MaterialLibrary.getMaterial(id);
}