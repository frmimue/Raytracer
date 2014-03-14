#include "Renderer.h"

#include <iostream>

Renderer::Renderer() {
    //ctor
}

Renderer::~Renderer() {
    //dtor
}

void renderLine(Scene *scene, Camera *camera, int width, int height, PixelBuffer *pixelBuffer, int i){
	for (int j = 0; j < width; j++) {
		Ray ray = camera->computeRay(j, i, width, height);
		Trace trace = scene->trace(ray);

		if (trace.object == nullptr)
			pixelBuffer->pixelBuffer[i * width + j] = Color(125, 150, 255) * pow(1 - ray.direction.z, 4);
		else {
			Color color = scene->illumination(ray, trace);
			if (trace.object->getReflection() > 0.0f){
				Vector3D tmpPoint(ray.position + ray.direction*trace.distance);
				Ray tmpRay(tmpPoint, ray.direction - trace.object->getNormal(tmpPoint) * 2.0f * (ray.direction * trace.object->getNormal(tmpPoint)));
				Trace tmpTrace = scene->trace(tmpRay);
				Color tmpColor;
				if (tmpTrace.object == nullptr)
					tmpColor = Color(125, 150, 255) * pow(1 - ray.direction.z, 4);
				else
					tmpColor = scene->illumination(tmpRay, tmpTrace);
				color = color * (1.0f - trace.object->getReflection()) + tmpColor * trace.object->getReflection();
			}

			pixelBuffer->pixelBuffer[i * width + j] = color;
		}
	}
	std::cout << "Rendered Line: " << i << std::endl;
}

PixelBuffer* Renderer::render(Scene *scene, Camera *camera, int width, int height) {
	PixelBuffer *pixelBuffer = new PixelBuffer(width, height);

	/*std::vector<std::thread> t;
	for (int i = 0; i < height; i++){
		t.push_back(std::thread(renderLine, scene, camera, width, height, &pixelBuffer, i));
	}

    for(int i = 0; i < height; i++) {
		t.at(i).join();
    }*/

#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
	for (int i = 0; i < height; i++) {
		renderLine(scene, camera, width, height, pixelBuffer, i);
	}

	return pixelBuffer;
}
