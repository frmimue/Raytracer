#include "Scene.h"


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
	for each (Object *object in Objects)
	{
		float distance = object->hitDistance(ray);
		if (distance > 0 && distance < minDistance){
			pObject = object;
			minDistance = distance;
		}
	}
	if (pObject != nullptr)
		return pObject->getColor();
	return Color(25, 25, 25);
}


void Scene::add(Object *object){
	this->Objects.push_back(object);
}
