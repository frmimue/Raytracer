#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"

int main(int argv, char** argc){

	int testX = 800, testY = 600;

	Ray testRay = Ray::Ray(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
	SphereObject testSphere = SphereObject::SphereObject(Vector3D(0, 3, 0), 1.0, Color(255, 0, 0));
	Camera testCamera = Camera::Camera(Vector3D(0, 0, 0), Vector3D(0, 1, 0), testX, testY);

	std::cout << testSphere.hitDistance(testRay) << std::endl << std::endl;

	Color a = Color::Color(255, 0, 255);
	Color b = Color::Color(a);

	std::cout << a.red << std::endl << std::endl;

	while (false){
		int x, y;
		std::cin >> x;
		std::cin >> y;
		std::cout << testSphere.hitDistance(testCamera.computeRay(x, y)) << std::endl;
	}

	std::cout << std::endl << "Creating test PPM file: test.ppm" << std::endl;

	PixelBuffer* testBuffer = new PixelBuffer(testX, testY);
	for (int i = 0; i < testY; i++){
		for (int j = 0; j < testX; j++){
			if (testSphere.hitDistance(testCamera.computeRay(j, i)) > 1)
				testBuffer->pixelBuffer[i * testX + j] = testSphere.color;
		}
	}
	testBuffer->savePPM("test.ppm");
	
	std::cout << std::endl << "Creating random PPM file: 123.ppm" << std::endl;

	PixelBuffer* pixelBuffer = new PixelBuffer(1920, 1080);
	pixelBuffer->randomize();
	pixelBuffer->savePPM("123.ppm");
	return 0;
}