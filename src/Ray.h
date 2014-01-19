#pragma once

#include "Vector3D.h"

class Ray
{
public:
    Vector3D position;
    Vector3D direction;
private:
public:
    Ray(Vector3D, Vector3D);
    ~Ray();
private:
};
