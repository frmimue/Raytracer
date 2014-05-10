#pragma once

#include "Object.h"
#include "Vector3D.h"
#include "Color.h"

class TriangleObject :
	public Object {
private:
	Vector3D position0;
	Vector3D position1;
	Vector3D position2;
	Vector3D normal;
	Color color;
	float reflection;
	float refraction;
	float ior;
public:
	TriangleObject(Vector3D, Vector3D, Vector3D, Color, float, float, float);
	~TriangleObject();
	float hitDistance(Ray, bool &);
	Color getColor(Vector3D point);
	Vector3D getNormal(Vector3D);
	float getReflection();
	float getRefraction();
	float getIOR(){ return ior; }
};
