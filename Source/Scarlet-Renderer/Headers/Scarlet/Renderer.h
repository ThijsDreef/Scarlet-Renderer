#pragma once
#include "Scarlet/RenderBuffer.h"
#include "Scarlet/Camera.h"
#include "Scarlet/Scene.h"
#include "Scarlet/Utils/Timer.h"
#include <thread>
#include <string>

class Renderer {
private:
    RenderBuffer m_RenderBuffer;
    void renderPixel(unsigned int id, Scene& scene, Camera& camera);
    void renderPixels(unsigned int start, unsigned int end, Scene& scene, Camera& camera);
    unsigned int m_aaFactor = 32;
public:
    void renderScene(Scene& scene, Camera& camera);
    void renderSceneMultiThreaded(Scene& scene, Camera& camera, unsigned int threadCount);
    void setRenderDimensions(unsigned int w, unsigned int h);
    void writeRenderBuffer(const char* fileName);
    Renderer();
    ~Renderer();
};