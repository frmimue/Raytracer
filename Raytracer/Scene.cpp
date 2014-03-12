#include "Scene.h"

#include <math.h>

Scene::Scene() {
}


Scene::~Scene() {
}

Trace Scene::trace(Ray ray) {
    float minDistance = 1000000000;
    Object *pObject = nullptr;

    for(Object *object : objects) {
        float distance = object->hitDistance(ray);

        if(distance > 0.00001f && distance < minDistance) {
            pObject = object;
            minDistance = distance;
        }
    }
    return Trace(pObject, minDistance);

    //if(pObject == nullptr)
    //    return Color(125, 150, 255) * pow(1 - ray.direction.z, 4);
    //
    //return traceLight(ray, pObject, minDistance);
}

Color Scene::illumination(Ray &ray, Trace &trace){
    Color lightColor = Color(0, 0, 0);
    Ray lightRay = Ray(Vector3D(ray.position + ray.direction * trace.distance), Vector3D(0, 0, 0));
    bool hit = false;

    for(Light *light : lights) {
        lightRay.direction = !Vector3D(light->position - lightRay.position);

        for(Object *object : objects) {
            if(object == trace.object)
                break;

            if(object->hitDistance(lightRay) > 0.00001f) {
                hit = true;
                break;
            }
        }

        if(hit) {
            hit = false;
            continue;
        }

        float n = 128.0f;
        lightColor = lightColor
                    +  trace.object->getColor(lightRay.position) * ((lightRay.direction * trace.object->getNormal(lightRay.position)))
                    + Color(255, 255, 255) * pow((((-ray.direction + lightRay.direction) * trace.object->getNormal(lightRay.position)) / ((-ray.direction + lightRay.direction).length())), n);
    }

    return lightColor;
}

Color Scene::old(Ray &ray){
    float minDistance = 1000000000;
    Object *pObject = nullptr;

    for(Object *object : objects) {
        float distance = object->hitDistance(ray);

        if(distance > 0.00001f && distance < minDistance) {
            pObject = object;
            minDistance = distance;
        }
    }

    if(pObject == nullptr)
        return Color(125, 150, 255) * pow(1 - ray.direction.z, 4);

    Color lightColor = Color(0, 0, 0);
    Ray lightRay = Ray(Vector3D(ray.position + ray.direction * minDistance), Vector3D(0, 0, 0));
    bool hit = false;

    for(Light *light : lights) {
        lightRay.direction = !Vector3D(light->position - lightRay.position);

        for(Object *object : objects) {
            if(object == pObject)
                break;

            if(object->hitDistance(lightRay) > 0.00001f) {
                hit = true;
                break;
            }
        }

        if(hit) {
            hit = false;
            continue;
        }

        float n = 128.0f;
        lightColor = lightColor
                    +  pObject->getColor(lightRay.position) * ((lightRay.direction * pObject->getNormal(lightRay.position)))
                    + Color(255, 255, 255) * pow((((-ray.direction + lightRay.direction) * pObject->getNormal(lightRay.position)) / ((-ray.direction + lightRay.direction).length())), n);
    }

    return lightColor + pObject->getColor(ray.position + ray.direction * minDistance) * 0.2f;
}


void Scene::add(Object *object) {
    this->objects.push_back(object);
}

void Scene::add(Light *light) {
    this->lights.push_back(light);
}
