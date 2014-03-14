#pragma once

#include "Scene.h"
#include "Camera.h"
#include "PixelBuffer.h"

class Renderer {
private:
public:
    Renderer();
    ~Renderer();
    PixelBuffer* render(Scene *, Camera *, int, int);
};
