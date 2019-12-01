#include "Scarlet/Objects/Pixel.h"

Pixel::Pixel() {
    r = 0;
    g = 0;
    b = 0;
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Pixel::~Pixel() {

}

Pixel::Pixel(const Color& c) {
    r = static_cast<unsigned char>(c.r * 255);
    g = static_cast<unsigned char>(c.g * 255);
    b = static_cast<unsigned char>(c.b * 255);
}