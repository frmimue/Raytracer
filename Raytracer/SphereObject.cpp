#include "SphereObject.h"
#include <math.h>
#include <Windows.h>

SphereObject::SphereObject(Vector3D position, float radius, Color color, float reflection, float refraction, float ior) : position(position), radius(radius), color(color), reflection(reflection), refraction(refraction), ior(ior) {
}

SphereObject::~SphereObject() {
}

float SphereObject::hitDistance(Ray ray, bool &inside) {

	Vector3D l = Vector3D(position - ray.position);
	float s = l * ray.direction;
	float l2 = l * l;
	float m2 = l2 - s * s;
	float r2 = radius * radius;
	if (s < 0 && l2 > r2 || m2 > r2)
		return -1;
	float q = sqrtf(r2 - m2);
	if (l2 < r2){
		inside = true;
		return s + q;
	}
	inside = false;
	return s - q;
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

float SphereObject::getRefraction(){
	return refraction;
}