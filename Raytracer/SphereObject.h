#pragma once

#include "Object.h"
#include "Color.h"

class SphereObject : public Object {
public:
    Vector3D position;
    float radius;
    Color color;
	float reflection;
	float refraction;
	float ior;
public:
    SphereObject(Vector3D, float, Color, float, float, float);
    ~SphereObject();
	float hitDistance(Ray, bool &);
    Color getColor(Vector3D);
    Vector3D getPosition();
    Vector3D getNormal(Vector3D);
	float getReflection();
	float getRefraction();
	float getIOR(){ return ior; }
};
