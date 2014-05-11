#pragma once
#include "Light.h"
class DirectionLight :
	public Light
{
private:
	Vector3D direction;
public:
	DirectionLight(Vector3D direction);
	~DirectionLight();
	Ray lightRay(Vector3D);
};

