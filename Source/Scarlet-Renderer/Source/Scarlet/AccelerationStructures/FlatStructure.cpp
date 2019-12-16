#include "Scarlet/AccelerationStructures/FlatStructure.h"

#include <iostream>
FlatStructure::FlatStructure() {

}

FlatStructure::~FlatStructure() {

}

Renderable* FlatStructure::getObject(const Ray& ray) {
    float closest = 999.0f;
    unsigned int closestObject = objects.size();
    for (unsigned int i = 0; i < objects.size(); i++) {
        float t = objects[i]->intersect(ray);
        if (t < closest && t > 0) {
            closest = t;
            closestObject = i;
        }
    }    
    
    return (closestObject != objects.size()) ? objects[closestObject] : nullptr;
}

void FlatStructure::removeObject(Renderable* object) {
    //swap object to back pop
}

void FlatStructure::addObject(Renderable* object) {
    objects.push_back(object);
}