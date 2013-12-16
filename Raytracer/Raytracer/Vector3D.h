#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;
public:
	Vector3D(float, float, float);
	~Vector3D();
	Vector3D operator+(Vector3D const&);
	Vector3D operator-(Vector3D const&);
	Vector3D operator%(Vector3D const&);
	Vector3D operator!();
	Vector3D operator-();
	float operator*(Vector3D const&);
	Vector3D operator*(float const&);
	float length();
	float square();
};

