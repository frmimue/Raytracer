#pragma once

#include "Ray.h"

class Camera {
private:
    Vector3D position;
    Vector3D direction;
	Vector3D up;
	Vector3D right;
public:
    Camera(Vector3D, Vector3D, float);
    ~Camera();
    Ray computeRay(int, int, int, int);
};
