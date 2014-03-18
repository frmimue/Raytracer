#pragma once

#include "Scene.h"
#include "Camera.h"
#include "PixelBuffer.h"

class Renderer {
private:
	void renderLine(Scene *scene, Camera *camera, int width, int height, PixelBuffer *pixelBuffer, int i, int);
	Color trace(Ray &, Scene *, int, int);
public:
    Renderer();
    ~Renderer();
    PixelBuffer* render(Scene *, Camera *, int, int, int);
};
