#include "Trace.h"

Trace::Trace(Object *object, float distance, bool inside) : object(object), distance(distance), inside(inside) {
    //ctor
}

Trace::~Trace() {
    //dtor
}
