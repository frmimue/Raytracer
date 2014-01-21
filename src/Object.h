#pragma once

#include "Ray.h"
#include "Color.h"

class Object {
public:
    Object() {};
    virtual ~Object() {};
    virtual float hitDistance(Ray) = 0;
    virtual Color getColor(Vector3D) = 0;
    virtual Vector3D getNormal(Vector3D) = 0;
private:
};
