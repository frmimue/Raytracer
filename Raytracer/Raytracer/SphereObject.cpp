#include "SphereObject.h"
#include <math.h>


SphereObject::SphereObject(Vector3D position, float radius, Color color) : position(position), radius(radius), color(color)
{
}


SphereObject::~SphereObject()
{
}

float SphereObject::hitDistance(Ray ray){

	float tmp = ray.direction * (ray.position - position);
	float root = (float)sqrt(tmp*tmp - (ray.position - position).square() + radius*radius);
	if (root < 0)
		return -1.0f;
	return -tmp - root;
}

float SphereObject::hitDistance2(Ray ray){

	float tmp = ray.direction * (ray.position - position);
	float root = (float)sqrt(tmp*tmp - (ray.position - position).square() + radius*radius);
	if (root < 0)
		return -1.0f;
	return -tmp + root;
}


Color SphereObject::getColor(){
	return this->color;
}


Vector3D SphereObject::getPosition(){
	return this->position;
}


Vector3D SphereObject::getNormal(Vector3D point){
	return !(point - position);
}
