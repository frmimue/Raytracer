#include "PlaneObject.h"

#include <math.h>

#include "Vector3D.h"
#include "Object.h"
PlaneObject::PlaneObject(Vector3D position, Vector3D normal, Color color1, Color color2, float reflection, float refraction, float ior) : position(position), normal(normal), color1(color1), color2(color2), reflection(reflection), refraction(refraction), ior(ior) {
}


PlaneObject::~PlaneObject() {
}


float PlaneObject::hitDistance(Ray ray, bool &) {
    return ((position - ray.position) * normal) / (ray.direction * normal);
}

float PlaneObject::hitDistance2(Ray ray) {
    return ((position - ray.position) * normal) / (ray.direction * normal);
}


Color PlaneObject::getColor(Vector3D point) {
    return ((int)(ceil(point.x) + ceil(point.y)) & 1 ? color1 : color2);
}


Vector3D PlaneObject::getPosition() {
    return this->position;
}

Vector3D PlaneObject::getNormal(Vector3D) {
    return this->normal;
}

float PlaneObject::getReflection(){
	return reflection;
}

float PlaneObject::getRefraction(){
	return refraction;
}