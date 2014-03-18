#pragma once

#include "Object.h"

class Trace {
public:
    Object *object;
    float   distance;
	bool	inside;
private:
public:
    Trace(Object *, float, bool);
    ~Trace();
private:
};
