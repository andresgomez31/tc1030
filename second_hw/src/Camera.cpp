// File: Camera.cpp

#include "Camera.hpp"

Camera::Camera() 
    : lensSize(3.5) {}

Camera::Camera(float lensSize) : lensSize(lensSize) {}

float Camera::getLensSize() {
    return lensSize;
}

void Camera::takePicture() {
    std::time_t timestamp = std::time(nullptr);
    std::cout << "Picture taken at " << std::asctime(std::localtime(&timestamp));
}