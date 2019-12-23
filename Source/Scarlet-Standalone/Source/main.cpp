#include <iostream>
#include "Scarlet/Renderer.h"
#include "Scarlet/AccelerationStructures/FlatStructure.h"
#include "Scarlet/Renderables/Sphere.h"
#include "Scarlet/Renderables/Plane.h"
#include "Scarlet/Materials/ColorMaterial.h"

int main() {
    Renderer r;
    Camera c = Camera(Vector3F(0, 0, -1), 60);
    Scene s = Scene(new FlatStructure());

    unsigned int id = s.addMaterial(new ColorMaterial(Color(0, 1, 0)));
    unsigned int id1 = s.addMaterial(new ColorMaterial(Color(1, 1, 0)));


    c.m_Transform.translateBy(Vector3F(0, 0, 0));

    Renderable* test = new Sphere(1.0f);
    test->translate(Vector3F(2, 2, -10));
    test->m_materialId = id;
    s.addObject(test);

    test = new Plane(Vector3F(0, 1, 0));
    test->translate(Vector3F(0, -3, 0));
    s.addObject(test);
    

    test = new Sphere(1.0f);
    test->translate(Vector3F(-1, 0, -5));
    test->scale(Vector3F(2, 2, 2));
    test->m_materialId = id1;
    s.addObject(test);

    r.setRenderDimensions(800, 800);
    r.renderScene(s, c);

    r.writeRenderBuffer("output.png");


    return 0;
}