#pragma once

#include "Object.h"
#include "Color.h"

class SphereObject : public Object {
public:
    Vector3D position;
    float radius;
    Color color;
public:
    SphereObject(Vector3D, float, Color);
    ~SphereObject();
    float hitDistance(Ray);
    Color getColor(Vector3D);
    Vector3D getPosition();
    Vector3D getNormal(Vector3D);
};
