#pragma once

#include "Vector3D.h"
#include "Ray.h"

class Light {
public:
	Light(){};
	virtual ~Light(){};
	virtual Ray lightRay(Vector3D) = 0;
};
