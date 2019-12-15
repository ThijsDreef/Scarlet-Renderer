#pragma once
#include "Scarlet/Objects/Color.h"

class Pixel {
public:
    unsigned char r, g, b;
    Pixel();
    Pixel(const Color& c);
    Pixel(unsigned char r, unsigned char g, unsigned char b);
    ~Pixel();
};