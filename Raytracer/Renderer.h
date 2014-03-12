#pragma once

#include "Scene.h"
#include "Camera.h"
#include "PixelBuffer.h"

class Renderer {
public:
private:
public:
    Renderer();
    ~Renderer();
    void render(Scene *, Camera *, int, int, PixelBuffer *);
private:
};
