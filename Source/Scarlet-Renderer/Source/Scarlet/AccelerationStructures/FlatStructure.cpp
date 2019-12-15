#include "Scarlet/AccelerationStructures/FlatStructure.h"

FlatStructure::FlatStructure() {

}

FlatStructure::~FlatStructure() {

}

Renderable* FlatStructure::getObject(const Ray& ray) {
    float closest = 1000.0f;
    unsigned int closestObject = objects.size();
    for (unsigned int i = 0; i < objects.size(); i++) {
        float t = objects[i]->intersect(ray);
        if (t < closest) {
            closest = t;
            closestObject = i;
        }
    }    
    return objects[closestObject];
}

void FlatStructure::removeObject(Renderable* object) {
    //swap object to back pop
}

void FlatStructure::addObject(Renderable* object) {
    objects.push_back(object);
}