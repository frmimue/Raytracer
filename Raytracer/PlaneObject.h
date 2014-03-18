#pragma once

#include "Object.h"
#include "Vector3D.h"
#include "Color.h"

class PlaneObject :
    public Object {
private:
    Vector3D position;
    Vector3D normal;
    Color color1;
    Color color2;
	float reflection;
	float refraction;
	float ior;
public:
    PlaneObject(Vector3D, Vector3D, Color, Color, float, float, float);
    ~PlaneObject();
	float hitDistance(Ray, bool &);
    float hitDistance2(Ray);
    Color getColor(Vector3D point);
    Vector3D getPosition();
    Vector3D getNormal(Vector3D);
	float getReflection();
	float getRefraction();
	float getIOR(){ return ior; }
};
