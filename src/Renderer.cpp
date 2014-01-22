#include "Renderer.h"

Renderer::Renderer() {
    //ctor
}

Renderer::~Renderer() {
    //dtor
}

void Renderer::render(Scene *scene, Camera *camera, int width, int height, PixelBuffer *pixelBuffer) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Ray ray = camera->computeRay(j, i, width, height);
            Trace trace = scene->trace(ray);

            if(trace.object == nullptr)
                pixelBuffer->pixelBuffer[i * width + j] = Color(125, 150, 255) * pow(1 - ray.direction.z, 4);
            else {
                Color color = scene->illumination(ray, trace);
                color = color + trace.object->getColor(ray.position + ray.direction * trace.distance) * 0.2f;
                pixelBuffer->pixelBuffer[i * width + j] = color;
            }
        }
    }
}
