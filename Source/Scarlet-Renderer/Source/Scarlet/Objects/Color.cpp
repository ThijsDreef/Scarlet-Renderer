#include "Scarlet/Objects/Color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::~Color() {

}