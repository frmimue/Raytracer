#include "Camera.h"

Camera::Camera(Vector3D position, Vector3D direction) : position(position), direction(!direction) {
}


Camera::~Camera() {
}


Ray Camera::computeRay(int x, int y, int width, int height) {
    float xPart = x / (float)width;
    float yPart = y / (float)height;
    xPart = -0.5f + xPart;
    yPart = ((float)height / (float)width) * (0.5f - yPart);
    return Ray(position, !Vector3D(xPart, 1.0f, yPart));
}
