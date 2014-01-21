#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Scene.h"
#include "PlaneObject.h"

int main(int argv, char **argc) {
    int testX = 1600, testY = 1200;
    Camera testCamera = Camera(Vector3D(0, -5, 1), Vector3D(0, 1, 0), testX, testY);
    Scene *scene = new Scene();
    SphereObject testSphere2 = SphereObject(Vector3D(1, 3, -0.3), 0.7, Color(255, 0, 0));
    SphereObject testSphere3 = SphereObject(Vector3D(-1, 2, 0), 0.7, Color(0, 0, 255));
    PlaneObject *testPlane = new PlaneObject(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Color(0, 255, 0), Color(255, 255, 255));
    scene->add(&testSphere2);
    scene->add(&testSphere3);
    scene->add(testPlane);
    scene->add(new Light(Vector3D(2, 1, 1)));
    scene->add(new Light(Vector3D(-2, 1, 1)));
    std::cout << std::endl << "Creating test3 PPM file: test3.ppm" << std::endl;
    PixelBuffer *testBuffer = new PixelBuffer(testX, testY);

    for(int i = 0; i < testY; i++) {
        for(int j = 0; j < testX; j++) {
            testBuffer->pixelBuffer[i * testX + j] = scene->trace(testCamera.computeRay(j, i));
        }
    }

    testBuffer->savePPM("test.ppm");
    return 0;
}
