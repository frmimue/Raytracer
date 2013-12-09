#pragma once

#include "Vector3D.h"

class Light
{
public:
	Vector3D position;
	Light(Vector3D);
	~Light();
};

