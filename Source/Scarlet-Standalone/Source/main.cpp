#include <iostream>
#include "Scarlet/RenderBuffer.h"

int main() {
    int w = 256;
    int h = 256;
    RenderBuffer r;
    Color c;
    r.setRenderBufferSize(w, h);
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            c.r = (float)x / w;
            c.g = (float)y / h;
            r.setColor(x, y, c);
        }
    }
    r.writeBuffer("output.png");

    return 0;
}