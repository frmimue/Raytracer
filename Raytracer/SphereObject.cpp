#include "SphereObject.h"
#include <math.h>


SphereObject::SphereObject(Vector3D position, float radius, Color color, float reflection) : position(position), radius(radius), color(color), reflection(reflection) {
}

SphereObject::~SphereObject() {
}

float SphereObject::hitDistance(Ray ray) {
    float tmp = ray.direction * (ray.position - position);
    float root = tmp * tmp - (ray.position - position).square() + radius * radius;

    if(root < 0)
        return -1.0f;

    return -tmp - sqrtf(root);
}


Color SphereObject::getColor(Vector3D point) {
    return this->color;
}


Vector3D SphereObject::getPosition() {
    return this->position;
}


Vector3D SphereObject::getNormal(Vector3D point) {
    return !(point - position);
}

float SphereObject::getReflection(){
	return reflection;
}