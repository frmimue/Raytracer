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
	float root = (float)sqrt(tmp*tmp - (ray.position-position).length() + radius*radius);
	if (root < 0)
		return -1.0f;
	return -tmp - root;
}


Color SphereObject::getColor(){
	return this->color;
}
