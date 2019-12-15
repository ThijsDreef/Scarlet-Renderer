#pragma once
#include "Scarlet/AccelerationStructures/AccelerationStructure.h"
#include <vector>


class FlatStructure : public AccelerationStructure {
public:
    std::vector<Renderable*> objects;

    Renderable* getObject(const Ray& ray);
    void removeObject(Renderable* object);
    void addObject(Renderable* object);

    FlatStructure();
    ~FlatStructure();
};