#include "Scarlet/AccelerationStructures/AccelerationStructure.h"
#include "Scarlet/Objects/Color.h"
#include "Scarlet/Materials/MaterialLibrary.h"

class Scene {  
private:
    AccelerationStructure* m_accelerationStructure;
    MaterialLibrary m_MaterialLibrary;
    std::vector<Renderable*> m_Renderables;
public:
    void addObject(Renderable* object);
    unsigned int addMaterial(const Material* material);
    const Renderable* getObject(const Ray& ray);
    Material* getMaterial(unsigned int id);
    Scene(AccelerationStructure* accelerationStructure);
    ~Scene();
};