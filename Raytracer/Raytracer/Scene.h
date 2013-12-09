#pragma once

#include <vector>

#include "Object.h"
#include "Ray.h"
#include "Color.h"
#include "Light.h"

class Scene
{
private:
	std::vector<Object*> objects;
	std::vector<Light*> lights;
public:
	Scene();
	~Scene();
	Color trace(Ray ray);
	void add(Object *);
	void addLight(Light *);
};

