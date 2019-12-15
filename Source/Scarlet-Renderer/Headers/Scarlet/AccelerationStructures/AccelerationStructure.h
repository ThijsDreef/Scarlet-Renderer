#pragma once
#include "Scarlet/Renderables/Renderable.h"

class AccelerationStructure {
public:
    virtual Renderable* getObject(const Ray& ray) = 0;
    virtual void addObject(Renderable* object) = 0;
    virtual void removeObject(Renderable* object) = 0;
};