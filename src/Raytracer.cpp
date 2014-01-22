#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Scene.h"
#include "PlaneObject.h"
#include "Renderer.h"

int main(int argv, char **argc) {
    int testX = 2000, testY = 1000;
    Camera testCamera = Camera(Vector3D(0, -5, 1), Vector3D(0, 1, 0));
    Scene *scene = new Scene();
    SphereObject testSphere2 = SphereObject(Vector3D(1, 3, -0.3), 0.7, Color(255, 0, 0));
    SphereObject testSphere3 = SphereObject(Vector3D(-1, 2, 0), 0.7, Color(0, 0, 255));
    PlaneObject *testPlane = new PlaneObject(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Color(0, 255, 0), Color(255, 255, 255));
    scene->add(&testSphere2);
    scene->add(&testSphere3);
    scene->add(testPlane);
    scene->add(new Light(Vector3D(2, 1, 1)));
    scene->add(new Light(Vector3D(-2, 1, 1)));
    std::cout << std::endl << "Creating test.ppm" << std::endl;
    PixelBuffer *testBuffer = new PixelBuffer(testX, testY);
    PixelBuffer *testBuffer2 = new PixelBuffer(testX, testY);

    Renderer *renderer = new Renderer();
    renderer->render(scene, &testCamera, testX, testY, testBuffer);

    for(int i = 0; i < testY; i++) {
        for(int j = 0; j < testX; j++) {
            Ray ray = testCamera.computeRay(j, i, testX, testY);
            testBuffer2->pixelBuffer[i * testX + j] = scene->old(ray);
        }
    }

    testBuffer->savePPM("test.ppm");
    testBuffer2->savePPM("test2.ppm");
    return 0;
}
