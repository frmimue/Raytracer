#pragma once

#include <vector>

#include "Object.h"
#include "Ray.h"

class Scene
{
private:
	std::vector<Object*> Objects;
public:
	Scene();
	~Scene();
	void trace(Ray ray);
};

