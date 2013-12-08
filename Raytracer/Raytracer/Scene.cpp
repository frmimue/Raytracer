#include "Scene.h"


Scene::Scene()
{
}


Scene::~Scene()
{
}


void Scene::trace(Ray ray)
{
	for each (Object *object in Objects)
	{
		object->hitDistance(ray);
	}
}
