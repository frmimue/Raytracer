#include "PlaneObject.h"


PlaneObject::PlaneObject(Vector3D position, Vector3D normal, Color color) : position(position), normal(normal), color(color)
{
}


PlaneObject::~PlaneObject()
{
}


float PlaneObject::hitDistance(Ray ray){
	return ((position - ray.position) * normal) / (ray.direction*normal);
}


Color PlaneObject::getColor(){
	return this->color;
}