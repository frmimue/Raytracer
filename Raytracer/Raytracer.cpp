#include <iostream>
#include <fstream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Scene.h"
#include "PlaneObject.h"
#include "Renderer.h"

#include "JsonArray.h"
#include "JsonGroup.h"
#include "JsonValue.h"

int main(int argv, char **argc) {

	int testX = 800, testY = 600;
	Camera testCamera = Camera(Vector3D(0, -5, 1), Vector3D(0, 1, 0));
	Scene *scene = new Scene();

	std::ifstream sceneFile("scene.txt");

	if (!sceneFile)
		return 123;

	std::string s((std::istreambuf_iterator<char>(sceneFile)), std::istreambuf_iterator<char>());

	JsonGroup json(s);
	JsonArray objects(json.at("objects").Array());

	for (int i = 0; i < objects.size(); i++){
		JsonGroup object = objects.at(i).Group();

		std::string position = object.at("position").String();
		std::string radius = object.at("radius").String();
		std::string color = object.at("color").String();

		if (object.at("type").String().compare("sphere") == 0){
			scene->add(new SphereObject(Vector3D(object.at("position").Array().at(0).Float(), object.at("position").Array().at(1).Float(), object.at("position").Array().at(2).Float()),
				object.at("radius").Float(), Color(object.at("color").Array().at(0).Integer(), object.at("color").Array().at(1).Integer(), object.at("color").Array().at(2).Integer())));
		}
	}

    //SphereObject testSphere2 = SphereObject(Vector3D(1, 3, -0.3), 0.7, Color(255, 0, 0));
    //SphereObject testSphere3 = SphereObject(Vector3D(-1, 2, 0), 0.7, Color(0, 0, 255));
    PlaneObject *testPlane = new PlaneObject(Vector3D(0, 0, -1), Vector3D(0, 0, 1), Color(0, 255, 0), Color(255, 255, 255));
    //scene->add(&testSphere2);
    //scene->add(&testSphere3);
    scene->add(testPlane);
    scene->add(new Light(Vector3D(2, 1, 1)));
    scene->add(new Light(Vector3D(-2, 1, 1)));
    std::cout << std::endl << "Creating test.ppm" << std::endl;
    PixelBuffer *testBuffer = new PixelBuffer(testX, testY);
    PixelBuffer *testBuffer2 = new PixelBuffer(testX, testY);

    Renderer *renderer = new Renderer();
    renderer->render(scene, &testCamera, testX, testY, testBuffer);

    testBuffer->savePPM("test.ppm");
    return 0;
}
