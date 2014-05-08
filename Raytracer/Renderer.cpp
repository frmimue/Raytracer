#include "Renderer.h"

#include <iostream>
#include <Windows.h>

Renderer::Renderer() {
    //ctor
}

Renderer::~Renderer() {
    //dtor
}

Color Renderer::trace(Ray &ray, Scene *scene, int maxDepth, int depth){
	Trace trace = scene->trace(ray);

	Color ambient;
	Color specular;
	Color diffuse;
	Color reflection;
	Color refraction;

	if (maxDepth < depth)
		return Color();

	if (trace.object == nullptr)
		//return Color(125, 150, 255) * pow(1 - ray.direction.z, 4);
		return Color(0, 0, 0);

	scene->illumination(ray, trace, ambient, diffuse, specular);

	Vector3D point(ray.position + ray.direction*trace.distance);
	
	if (depth <= maxDepth && trace.object->getReflection() > 0.0f){
		Ray rlRay(point + trace.object->getNormal(point)*0.0001f, ray.direction - trace.object->getNormal(point) * 2.0f * (ray.direction * trace.object->getNormal(point)));
		reflection = this->trace(rlRay, scene, maxDepth, depth + 1);
	}

	if (maxDepth > depth && trace.object->getRefraction() > 0.0f){

		Vector3D normal = trace.object->getNormal(point);

		float n = trace.inside ? trace.object->getIOR() / 1.0f : 1.0f / trace.object->getIOR();
		Vector3D N = normal * (trace.inside ? -1.0f : 1.0f);
		float cosI = - N* ray.direction;
		float cosT2 = 1.0f - n * n * (1.0f - cosI * cosI);
		float root = sqrtf(cosT2);
		if (cosT2 > 0.0f)
		{
			Vector3D T = (ray.direction * n) + N * (n * cosI - root);
			refraction = this->trace(Ray(point + T * 0.0001f, T), scene, maxDepth, depth + 1);
		}
		else{
			normal = normal * -1.0f;
			Vector3D refldir = ray.direction - normal * 2.0f * (normal * ray.direction);
			Ray refl = Ray(point + normal * 0.0001f, refldir);
			refraction = this->trace(refl, scene, maxDepth, depth + 1);
		}
	}

	/*if (depth <= maxDepth && trace.object->getRefraction() > 0.0f){

		Vector3D direction = ray.direction, normal = trace.object->getNormal(point);

		float f = trace.object->getNormal(point) * ray.direction;
		bool b = lastInside ? f < 0.0f : f > 0.0f;


		Vector3D *t = trace.object->refract(direction, normal, b);

		if (t == nullptr){
			Ray rlRay(point - trace.object->getNormal(point)*0.0001f, ray.direction - trace.object->getNormal(point) * 2.0f * (ray.direction * trace.object->getNormal(point)));
			refraction = this->trace(rlRay, scene, maxDepth, depth + 1, true);
		}
		else{

			Ray rfRay = Ray(Vector3D(), Vector3D());

			if (b){
				rfRay = Ray(point + trace.object->getNormal(point)*0.001f, *t);
			}
			else{
				OutputDebugStringA("1\n");
				rfRay = Ray(point - trace.object->getNormal(point)*0.001f, *t);
			}

			delete t;

			refraction = this->trace(rfRay, scene, maxDepth, depth + 1, b);
		}
	}*/
	return ambient + diffuse * (1 - trace.object->getReflection() - trace.object->getRefraction()) + specular + reflection * trace.object->getReflection() + refraction * trace.object->getRefraction();
	
}

void Renderer::renderLine(Scene *scene, Camera *camera, int width, int height, PixelBuffer *pixelBuffer, int i, int maxDepth){

	for (int j = 0; j < width; j++) {
		Ray ray = camera->computeRay(j, i, width, height);
		Color c = this->trace(ray, scene, maxDepth, 0);
		pixelBuffer->pixelBuffer[i * width + j] = c;
	}
	std::cout << "Rendered Line: " << i << std::endl;
}

PixelBuffer* Renderer::render(Scene *scene, Camera *camera, int width, int height, int maxDepth) {
	PixelBuffer *pixelBuffer = new PixelBuffer(width, height);

#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
	for (int i = 0; i < height; i++) {
		renderLine(scene, camera, width, height, pixelBuffer, i, maxDepth);
	}

	return pixelBuffer;
}
