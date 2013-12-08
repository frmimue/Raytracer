#pragma once

#include <vector>

#include "Object.h"
#include "Ray.h"
#include "Color.h"

class Scene
{
private:
	std::vector<Object*> Objects;
public:
	Scene();
	~Scene();
	Color trace(Ray ray);
	void add(Object *);
};

