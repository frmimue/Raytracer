#pragma once
#include "Light.h"
class PointLight :
	public Light
{
private:
	Vector3D position;
public:
	PointLight(Vector3D);
	~PointLight();
	Ray lightRay(Vector3D);
};

