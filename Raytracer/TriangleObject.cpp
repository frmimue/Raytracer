#include "TriangleObject.h"

#include <math.h>

#include "Vector3D.h"
#include "Object.h"
TriangleObject::TriangleObject(Vector3D position0, Vector3D position1, Vector3D position2, Color color, float reflection, float refraction, float ior) : position0(position0), position1(position1), position2(position2), color(color), reflection(reflection), refraction(refraction), ior(ior) {
	normal = !((position1 - position0) % (position2 - position0));
}


TriangleObject::~TriangleObject() {
}


float TriangleObject::hitDistance(Ray ray, bool &) {
	float t = ((position0 - ray.position) * normal) / (ray.direction * normal);
	Vector3D hitPoint = ray.position + ray.direction * t;
	if (normal * ((position1 - position0) % (hitPoint - position0)) < 0)
		return -1.0f;
	if (normal * ((position2 - position1) % (hitPoint - position1)) < 0)
		return -1.0f;
	if (normal * ((position0 - position2)%(hitPoint - position2)) < 0)
		return -1.0f;
	return t;
}


Color TriangleObject::getColor(Vector3D point) {
	return color;
}

Vector3D TriangleObject::getNormal(Vector3D) {
	return this->normal;
}

float TriangleObject::getReflection(){
	return reflection;
}

float TriangleObject::getRefraction(){
	return refraction;
}