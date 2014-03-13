#include "Camera.h"

#include <cmath>

Camera::Camera(Vector3D position, Vector3D target, float roll) : position(position){
	up = Vector3D(sin(-roll), 0, -cos(-roll));
	direction = !(target - position);
	right = !(up % direction);
	up = !(right % direction);
}


Camera::~Camera() {
}


Ray Camera::computeRay(int x, int y, int width, int height) {
    float xPart = x / (float)width;
    float yPart = y / (float)height;
    xPart = -0.5f + xPart;
    yPart = ((float)height / (float)width) * (0.5f - yPart);
    return Ray(position, !(direction + right * xPart + up * yPart));
}
