#include "PointLight.h"


PointLight::PointLight(Vector3D position) : position(position)
{
}


PointLight::~PointLight()
{
}

Ray PointLight::lightRay(Vector3D point){
	return Ray(position, !(point - position));
}
