#include "Scarlet/RenderBuffer.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "Scarlet/Utils/stb_image_write.h"
#include <iostream>
RenderBuffer::RenderBuffer() {
    m_buffer = new Pixel[1];
    m_W = 1u;
    m_H = 1u;
}

RenderBuffer::~RenderBuffer() {
    delete[] m_buffer;
}

void RenderBuffer::writeBuffer(const char* fileName) { 
    stbi_write_png(fileName, m_W, m_H, 3, m_buffer, m_W * 3);
}

void RenderBuffer::setColor(unsigned int x, unsigned int y, Color color) {
    m_buffer[x + y * m_W] = color;
}

void RenderBuffer::setColor(unsigned int id, Color color) {
    m_buffer[id] = color;
}

void RenderBuffer::setRenderBufferSize(unsigned int w, unsigned int h) {
    m_W = w;
    m_H = h;
    delete[] m_buffer;
    m_buffer = new Pixel[w * h];
}