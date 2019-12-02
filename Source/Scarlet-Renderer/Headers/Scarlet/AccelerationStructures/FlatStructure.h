#include "Scarlet/AccelerationStructures/AccelerationStructure.h"
#include <vector>


class FlatStructure : public AccelerationStructure {
public:
    std::vector<Renderable*> objects;

    const Renderable& getObject(const Ray& ray);
    void removeObject(const Renderable* object);
    void addObject(const Renderable* object);

    FlatStructure();
    ~FlatStructure();
};