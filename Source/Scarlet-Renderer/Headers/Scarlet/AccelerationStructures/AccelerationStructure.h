#include "Scarlet/Renderables/Renderable.h"

class AccelerationStructure {
    virtual const Renderable& getObject(const Ray& ray) = 0;
    virtual void adddObject(const Renderable* object) = 0;
    virtual void removeObject(const Renderable* object) = 0;
};