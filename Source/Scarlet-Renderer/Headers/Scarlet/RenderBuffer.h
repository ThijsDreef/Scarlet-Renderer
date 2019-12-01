#include "Scarlet/Objects/Pixel.h"

class RenderBuffer {
private:
    Pixel* m_buffer;
    int m_w;
    int m_h;
public:
    void writeBuffer(const char* fileName);
    void setColor(int x, int y, Color color);
    void setRenderBufferSize(int w, int h);
    RenderBuffer();
    ~RenderBuffer();
};