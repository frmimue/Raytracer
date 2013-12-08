#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"

int main(int argv, char** argc){

	Ray testRay = Ray::Ray(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
	SphereObject testSphere = SphereObject::SphereObject(Vector3D(0, 10, 0), 1.5, Color(255, 0, 0));

	std::cout << testSphere.hitDistance(&testRay);

	int d;
	std::cin >> d;
	std::cout << "Creating random PPM file: 123.ppm" << std::endl;

	PixelBuffer* pixelBuffer = new PixelBuffer(1920, 1080);
	pixelBuffer->randomize();
	pixelBuffer->savePPM("123.ppm");
	return 0;
}