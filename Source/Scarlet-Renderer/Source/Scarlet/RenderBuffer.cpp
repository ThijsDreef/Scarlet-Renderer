#include "Scarlet/RenderBuffer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Scarlet/Utils/stb_image_write.h"
#include <iostream>
RenderBuffer::RenderBuffer() {
    m_buffer = new Pixel[1];
}

RenderBuffer::~RenderBuffer() {
    delete[] m_buffer;
}

void RenderBuffer::writeBuffer(const char* fileName) { 
    stbi_write_png(fileName, m_w, m_h, 3, m_buffer, m_w * 3);
}

void RenderBuffer::setColor(int x, int y, Color color) {
    m_buffer[x + y * m_w] = color;
}

void RenderBuffer::setRenderBufferSize(int w, int h) {
    m_w = w;
    m_h = h;
    delete[] m_buffer;
    m_buffer = new Pixel[w * h];
}