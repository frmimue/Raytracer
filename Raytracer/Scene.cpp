#include "Scene.h"

#include <math.h>

Scene::Scene() {
}


Scene::~Scene() {
}

Trace Scene::trace(Ray ray) {
    float minDistance = 1000000000;
    Object *pObject = nullptr;
	bool inside = false;

    for(Object *object : objects) {
		bool tmpInside;
        float distance = object->hitDistance(ray, tmpInside);

        if(distance > 0.0f && distance < minDistance) {
            pObject = object;
            minDistance = distance;
			inside = tmpInside;
        }
    }
    return Trace(pObject, minDistance, inside);
}

void Scene::illumination(Ray &ray, Trace &trace, Color& ambient, Color& diffuse, Color &specular){


	ambient = Color(0, 0, 0);
	diffuse = Color(0, 0, 0);
	specular = Color(0, 0, 0);

	Vector3D hitPoint(ray.position + ray.direction * trace.distance);
    bool hit = false;

    for(Light *light : lights) {
		Ray lightRay = light->lightRay(hitPoint);

		Trace lightTrace = this->trace(lightRay);
		if (lightTrace.object != trace.object)
			continue;


        float n = 128.0f;
		specular = specular + Color(255, 255, 255) * pow((((-ray.direction + -lightRay.direction) * trace.object->getNormal(hitPoint)) / ((-ray.direction + -lightRay.direction).length())), n);

        diffuse = diffuse + trace.object->getColor(hitPoint) * ((-lightRay.direction * trace.object->getNormal(hitPoint)));
    }
}


void Scene::add(Object *object) {
    this->objects.push_back(object);
}

void Scene::add(Light *light) {
    this->lights.push_back(light);
}
