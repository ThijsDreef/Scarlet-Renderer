#include "Scarlet/Objects/Pixel.h"

class RenderBuffer {
private:
    Pixel* m_buffer;
    int m_w;
    int m_h;
public:
    void writeBuffer(const char* fileName);
    void setColor(unsigned int x, unsigned int y, Color color);
    void setRenderBufferSize(unsigned int w, unsigned int h);
    RenderBuffer();
    ~RenderBuffer();
};