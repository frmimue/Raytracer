#include "DirectionLight.h"


DirectionLight::DirectionLight(Vector3D direction) :direction(!direction)
{
}


DirectionLight::~DirectionLight()
{
}

Ray DirectionLight::lightRay(Vector3D point){
	return Ray(point - (direction * 1000000.0f), direction);
}
