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

	int testX = 1920, testY = 1080;
	Camera testCamera = Camera(Vector3D(0, -8, 1.5), Vector3D(0, 1, 0));
	Scene *scene = new Scene();

	std::ifstream sceneFile("scene.txt");

	if (!sceneFile)
		return 123;

	std::string s((std::istreambuf_iterator<char>(sceneFile)), std::istreambuf_iterator<char>());

	JsonGroup json(s);
	JsonArray objects(json.at("objects").Array());
	JsonArray lights(json.at("lights").Array());

	for (int i = 0; i < objects.size(); i++){
		JsonGroup object = objects.at(i).Group();

		if (object.at("type").String().compare("sphere") == 0){
			scene->add(new SphereObject(Vector3D(object.at("position").Array().at(0).Float(), object.at("position").Array().at(1).Float(), object.at("position").Array().at(2).Float()),
				object.at("radius").Float(), Color(object.at("color").Array().at(0).Integer(), object.at("color").Array().at(1).Integer(), object.at("color").Array().at(2).Integer()), object.at("reflection").Float()));
		}

		if (object.at("type").String().compare("plane") == 0){
			scene->add(new PlaneObject(Vector3D(object.at("position").Array().at(0).Float(), object.at("position").Array().at(1).Float(), object.at("position").Array().at(2).Float()),
				Vector3D(object.at("normal").Array().at(0).Float(), object.at("normal").Array().at(1).Float(), object.at("normal").Array().at(2).Float()),
				Color(object.at("color").Array().at(0).Array().at(0).Integer(), object.at("color").Array().at(0).Array().at(1).Integer(), object.at("color").Array().at(0).Array().at(2).Integer()),
				Color(object.at("color").Array().at(1).Array().at(0).Integer(), object.at("color").Array().at(1).Array().at(1).Integer(), object.at("color").Array().at(1).Array().at(2).Integer()), object.at("reflection").Float()));
		}
	}

	for (int i = 0; i < lights.size(); i++){
		JsonGroup light = lights.at(i).Group();

		if (light.at("type").String().compare("point") == 0){
			scene->add(new Light(Vector3D(light.at("position").Array().at(0).Float(), light.at("position").Array().at(1).Float(), light.at("position").Array().at(2).Float())));
		}
	}

    std::cout << std::endl << "Creating test.ppm" << std::endl;
    PixelBuffer *testBuffer = new PixelBuffer(testX, testY);
    PixelBuffer *testBuffer2 = new PixelBuffer(testX, testY);

    Renderer *renderer = new Renderer();
    renderer->render(scene, &testCamera, testX, testY, testBuffer);

    testBuffer->savePPM("test.ppm");
    return 0;
}
