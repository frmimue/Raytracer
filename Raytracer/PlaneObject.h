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
public:
    PlaneObject(Vector3D, Vector3D, Color, Color, float);
    ~PlaneObject();
    float hitDistance(Ray);
    float hitDistance2(Ray);
    Color getColor(Vector3D point);
    Vector3D getPosition();
    Vector3D getNormal(Vector3D);
	float getReflection();
};
