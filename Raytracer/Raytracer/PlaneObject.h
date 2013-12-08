#pragma once
#include "Object.h"
class PlaneObject :
	public Object
{
private:
	Vector3D position;
	Vector3D normal;
	Color color;
public:
	PlaneObject(Vector3D, Vector3D, Color);
	~PlaneObject();
	float hitDistance(Ray);
	Color getColor();
};

