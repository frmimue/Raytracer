#include "Scene.h"
#include <iostream>

Scene::Scene()
{
}


Scene::~Scene()
{
}


Color Scene::trace(Ray ray)
{
	float minDistance = 1000000000;
	Object *pObject = nullptr;
	for each (Object *object in objects)
	{
		float distance = object->hitDistance(ray);
		if (distance > 0.1f && distance < minDistance){
			pObject = object;
			minDistance = distance;
		}
	}
	if (pObject == nullptr)
		return Color(25, 25, 100);

	bool hit = false;
	for each (Light *light in lights)
	{
		Ray lightRay = Ray::Ray(Vector3D(ray.position + ray.direction*minDistance), !Vector3D(light->position-(ray.position + ray.direction*minDistance)));
		float f = (lightRay.direction*pObject->getNormal(lightRay.position));
		return pObject->getColor()*f;
	}
	return Color(0, 0, 0);
}


void Scene::add(Object *object){
	this->objects.push_back(object);
}

void Scene::addLight(Light *light){
	this->lights.push_back(light);
}
