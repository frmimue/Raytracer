#include <iostream>

#include "PixelBuffer.h"
#include "SphereObject.h"
#include "Camera.h"
#include "Scene.h"
#include "PlaneObject.h"
#include "Renderer.h"
#include "PointLight.h"
#include "DirectionLight.h"
#include "TriangleObject.h"

#include "JsonArray.h"
#include "JsonGroup.h"
#include "JsonValue.h"

int main(int argv, char **argc) {

	Scene *scene = new Scene();

	std::ifstream sceneFile("scene.txt");

	if (!sceneFile)
		return 123;

	std::string s((std::istreambuf_iterator<char>(sceneFile)), std::istreambuf_iterator<char>());

	JsonGroup json(s);
	JsonArray objects(json.at("objects").Array());
	JsonArray lights(json.at("lights").Array());
	JsonGroup camera(json.at("camera").Group());

	Camera cam = Camera(Vector3D(camera.at("position").Array().at(0).Float(), camera.at("position").Array().at(1).Float(), camera.at("position").Array().at(2).Float()), Vector3D(camera.at("target").Array().at(0).Float(), camera.at("target").Array().at(1).Float(), camera.at("target").Array().at(2).Float()), camera.at("roll").Float());

	for (int i = 0; i < objects.size(); i++){
		JsonGroup object = objects.at(i).Group();

		if (object.at("type").String().compare("sphere") == 0){
			scene->add(new SphereObject(Vector3D(object.at("position").Array().at(0).Float(), object.at("position").Array().at(1).Float(), object.at("position").Array().at(2).Float()),
				object.at("radius").Float(), Color(object.at("color").Array().at(0).Integer(), object.at("color").Array().at(1).Integer(), object.at("color").Array().at(2).Integer()), object.at("reflection").Float(), object.at("refraction").Float(), object.at("ior").Float()));
		}

		if (object.at("type").String().compare("plane") == 0){
			scene->add(new PlaneObject(Vector3D(object.at("position").Array().at(0).Float(), object.at("position").Array().at(1).Float(), object.at("position").Array().at(2).Float()),
				Vector3D(object.at("normal").Array().at(0).Float(), object.at("normal").Array().at(1).Float(), object.at("normal").Array().at(2).Float()),
				Color(object.at("color").Array().at(0).Array().at(0).Integer(), object.at("color").Array().at(0).Array().at(1).Integer(), object.at("color").Array().at(0).Array().at(2).Integer()),
				Color(object.at("color").Array().at(1).Array().at(0).Integer(), object.at("color").Array().at(1).Array().at(1).Integer(), object.at("color").Array().at(1).Array().at(2).Integer()), object.at("reflection").Float(), object.at("refraction").Float(), object.at("ior").Float()));
		}

		if (object.at("type").String().compare("triangle") == 0){
			scene->add(new TriangleObject(Vector3D(object.at("vertices").Array().at(0).Array().at(0).Integer(), object.at("vertices").Array().at(0).Array().at(1).Integer(), object.at("vertices").Array().at(0).Array().at(2).Integer()),
				Vector3D(object.at("vertices").Array().at(1).Array().at(0).Integer(), object.at("vertices").Array().at(1).Array().at(1).Integer(), object.at("vertices").Array().at(1).Array().at(2).Integer()),
				Vector3D(object.at("vertices").Array().at(2).Array().at(0).Integer(), object.at("vertices").Array().at(2).Array().at(1).Integer(), object.at("vertices").Array().at(2).Array().at(2).Integer()),
				Color(object.at("color").Array().at(0).Integer(), object.at("color").Array().at(1).Integer(), object.at("color").Array().at(2).Integer()), object.at("reflection").Float(), object.at("refraction").Float(), object.at("ior").Float()));
		}
	}

	for (int i = 0; i < lights.size(); i++){
		JsonGroup light = lights.at(i).Group();

		if (light.at("type").String().compare("point") == 0){
			scene->add(new PointLight(Vector3D(light.at("position").Array().at(0).Float(), light.at("position").Array().at(1).Float(), light.at("position").Array().at(2).Float())));
		}

		if (light.at("type").String().compare("direction") == 0){
			scene->add(new DirectionLight(Vector3D(light.at("direction").Array().at(0).Float(), light.at("direction").Array().at(1).Float(), light.at("direction").Array().at(2).Float())));
		}
	}

    Renderer *renderer = new Renderer();
	PixelBuffer *buffer = renderer->render(scene, &cam, camera.at("resolution").Array().at(0).Integer(), camera.at("resolution").Array().at(1).Integer(), camera.at("raydepth").Integer());
	buffer->savePPM("test.ppm");
    return 0;
}
