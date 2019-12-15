#pragma once
#include "Scarlet/Objects/Pixel.h"

class RenderBuffer {
private:
    Pixel* m_buffer;
    unsigned int m_W;
    unsigned int m_H;
public:
    void writeBuffer(const char* fileName);
    void setColor(unsigned int x, unsigned int y, Color color);
    void setColor(unsigned int id, Color color);
    void setRenderBufferSize(unsigned int w, unsigned int h);
    unsigned int getWidth() { return m_W; };
    unsigned int getHeight() { return m_H; };
    RenderBuffer();
    ~RenderBuffer();
};