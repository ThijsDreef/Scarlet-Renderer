#include "Scarlet/RenderBuffer.h"
#include "Scarlet/Camera.h"
#include "Scarlet/Scene.h"
#include <string>

class Renderer {
private:
    RenderBuffer m_RenderBuffer;
public:
    void renderScene(Scene& scene, Camera& camera);
    void setRenderDimensions(unsigned int w, unsigned int h);
    void writeRenderBuffer(const char* fileName);
    Renderer();
    ~Renderer();
};