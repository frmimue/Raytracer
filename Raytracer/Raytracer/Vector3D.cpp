#include "Vector3D.h"


Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z)
{
}


Vector3D::~Vector3D()
{
}


Vector3D Vector3D::operator+(Vector3D const& b){
	return Vector3D(x + b.x, y + b.y, z + b.z);
}


Vector3D Vector3D::operator-(Vector3D const& b){
	return Vector3D(x - b.x, y - b.y, z - b.z);
}


Vector3D Vector3D::operator!(){
	float length = this->length();
	return Vector3D(x/length,y/length,z/length);
}


float Vector3D::operator*(Vector3D const& b){
	return x*b.x + y*b.y + z*b.z;
}

Vector3D Vector3D::operator%(Vector3D const& b){
	return Vector3D(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
}


float Vector3D::length(){
	return (*this)*(*this);
}