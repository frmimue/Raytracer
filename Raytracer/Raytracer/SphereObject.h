#pragma once

#include "Object.h"
#include "Color.h"

class SphereObject : public Object
{
private:
	Vector3D position;
	float radius;
	Color color;
public:
	SphereObject(Vector3D, float, Color);
	~SphereObject();
	float hitDistance(Ray);
};

