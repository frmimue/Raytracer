#pragma once

#include "Ray.h"

class Camera
{
private:
	Vector3D position;
	Vector3D direction;
	int width;
	int height;
public:
	Camera(Vector3D, Vector3D, int, int);
	~Camera();
	Ray computeRay(int, int);
};
