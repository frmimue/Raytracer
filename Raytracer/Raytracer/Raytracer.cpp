#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Scene.h"
#include "PlaneObject.h"

int main(int argv, char** argc){

	int testX = 800, testY = 800;

	Ray testRay = Ray::Ray(Vector3D(0, 0, 0), Vector3D(0, 1, 0));
	SphereObject testSphere = SphereObject::SphereObject(Vector3D(0, 5, 0), 1.0, Color(255, 0, 0));
	Camera testCamera = Camera::Camera(Vector3D(0, -5, 0), Vector3D(0, 1, 0), testX, testY);

	std::cout << testSphere.hitDistance(testRay) << std::endl << std::endl;

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
				testBuffer->pixelBuffer[i * testX + j] = testSphere.getColor();
		}
	}
	testBuffer->savePPM("test.ppm");

	Scene *scene = new Scene();
	SphereObject testSphere2 = SphereObject::SphereObject(Vector3D(1, 3, 0), 1.2, Color(255, 0, 0));
	SphereObject testSphere3 = SphereObject::SphereObject(Vector3D(-1, 3, 0), 1.2, Color(0, 0, 255));
	PlaneObject *testPlane = new PlaneObject(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Color(0, 255,0));

	//scene->add(&testSphere2);
	//scene->add(&testSphere3);
	scene->add(&testSphere);
	scene->add(testPlane);

	std::cout << std::endl << "Creating test2 PPM file: test2.ppm" << std::endl;

	PixelBuffer* testBuffer2 = new PixelBuffer(testX, testY);
	for (int i = 0; i < testY; i++){
		for (int j = 0; j < testX; j++){
			testBuffer2->pixelBuffer[i * testX + j] = scene->trace(testCamera.computeRay(j, i));
		}
	}
	testBuffer2->savePPM("test2.ppm");

	scene->addLight(new Light(Vector3D(3, 3, 0)));

	std::cout << std::endl << "Creating test3 PPM file: test3.ppm" << std::endl;

	PixelBuffer* testBuffer3 = new PixelBuffer(testX, testY);
	for (int i = 0; i < testY; i++){
		for (int j = 0; j < testX; j++){
			testBuffer3->pixelBuffer[i * testX + j] = scene->trace(testCamera.computeRay(j, i));
		}
	}
	testBuffer3->savePPM("test3.ppm");
	
	std::cout << std::endl << "Creating random PPM file: 123.ppm" << std::endl;

	PixelBuffer* pixelBuffer = new PixelBuffer(1920, 1080);
	pixelBuffer->randomize();
	pixelBuffer->savePPM("123.ppm");
	return 0;
}