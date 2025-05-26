// File: Camera.hpp

#pragma once
#include <iostream> 
#include <ctime>
#include <string>

class Camera {
    private:
        float lensSize;

    public:
        Camera();
        Camera(float lensSize);

        float getLensSize();

        virtual void takePicture();
};