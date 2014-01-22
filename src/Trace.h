#pragma once

#include "Object.h"

class Trace {
public:
    Object *object;
    float   distance;
private:
public:
    Trace(Object *, float);
    ~Trace();
private:
};
