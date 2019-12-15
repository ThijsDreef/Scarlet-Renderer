#include <iostream>
#include "Scarlet/Renderer.h"
#include "Scarlet/AccelerationStructures/FlatStructure.h"

int main() {
    Renderer r;
    Camera c = Camera(Vector3F(0, 0, -1), 60);
    Scene s = Scene(new FlatStructure());
    r.setRenderDimensions(1920, 1080);

    r.renderScene(s, c);
    r.writeRenderBuffer("ouptut.png");


    return 0;
}