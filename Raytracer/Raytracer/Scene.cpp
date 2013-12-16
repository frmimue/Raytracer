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
	for (Object *object : objects)
	{
		float distance = object->hitDistance(ray);
		if (distance > 0.00001f && distance < minDistance){
			pObject = object;
			minDistance = distance;
		}
	}
	if (pObject == nullptr)
		return Color(125, 150, 255)*pow(1-ray.direction.z, 4);


	Color lightColor = Color::Color(0, 0, 0);

	bool hit = false;
	for  (Light *light : lights)
	{
		Ray lightRay = Ray::Ray(Vector3D(ray.position + ray.direction*minDistance), !Vector3D(light->position - (ray.position + ray.direction*minDistance)));
		
		for (Object *object : objects)
		{
			if (object == pObject)
				break;
			if (object->hitDistance(lightRay) > 0.00001f && object->hitDistance(lightRay) < (light->position - (ray.position + ray.direction*minDistance)).length()){
				hit = true;
				break;
			}
		}
		if (hit){
			hit = false;
			continue;
		}

		int n = 128.0f;

		lightColor = lightColor +  pObject->getColor(lightRay.position)*((lightRay.direction*pObject->getNormal(lightRay.position))) + Color(255, 255, 255)* pow((((-ray.direction + lightRay.direction) * pObject->getNormal(lightRay.position)) / ((-ray.direction + lightRay.direction).length())), n);
	}
	return lightColor + pObject->getColor(ray.position + ray.direction*minDistance) * 0.2f;
}


void Scene::add(Object *object){
	this->objects.push_back(object);
}

void Scene::addLight(Light *light){
	this->lights.push_back(light);
}
