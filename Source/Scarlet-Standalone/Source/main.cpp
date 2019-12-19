#include <iostream>
#include "Scarlet/Renderer.h"
#include "Scarlet/AccelerationStructures/FlatStructure.h"
#include "Scarlet/Renderables/Sphere.h"

int main() {
    Renderer r;
    Camera c = Camera(Vector3F(0, 0, -1), 60);
    Scene s = Scene(new FlatStructure());
    Sphere* test = new Sphere(1.0f);
    test->translate(Vector3F(2, 2, -10));
    s.addObject(test);
    c.m_Transform.translateBy(Vector3F(0, 0, 0));
    // c.m_Transform.rotateBy(Vector3F(0, -0.2, 0));
    // test->scale(Vector3F(2, 2, 2));

    // test = new Sphere(1.0f);
    // test->translate(Vector3F(1, 0, -5));
    // test->scale(Vector3F(2, 2, 2));
    // s.addObject(test);
    r.setRenderDimensions(1920, 1080);
    r.renderScene(s, c);

    r.writeRenderBuffer("output.png");


    return 0;
}