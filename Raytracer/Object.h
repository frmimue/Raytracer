#pragma once

#include "Ray.h"
#include "Color.h"

class Object {
public:
    Object() {};
    virtual ~Object() {};
    virtual float hitDistance(Ray, bool &) = 0;
    virtual Color getColor(Vector3D) = 0;
	virtual Vector3D getNormal(Vector3D) = 0;
	virtual float getReflection() = 0;
	virtual float getRefraction() = 0;
	virtual float getIOR() = 0;
private:
};
