#pragma once

#include <list>

#include "Object.h"
#include "Light.h"
#include "Ray.h"
#include "Color.h"

class Scene {
private:
    std::list<Object *> objects;
    std::list<Light *> lights;
public:
    Scene();
    ~Scene();
    void add(Object *);
    void add(Light *);
    Color trace(Ray);
private:
    Color traceLight(Ray, Object *, float);
};
