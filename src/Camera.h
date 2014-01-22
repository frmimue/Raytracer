#pragma once

#include "Ray.h"

class Camera {
private:
    Vector3D position;
    Vector3D direction;
public:
    Camera(Vector3D, Vector3D);
    ~Camera();
    Ray computeRay(int, int, int, int);
};
