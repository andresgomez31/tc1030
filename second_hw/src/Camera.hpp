#pragma once
#include <iostream> 
#include <ctime>

class Camera {
    private:
        float lensSize;

    public:
        Camera();
        Camera(float lensSize);

        virtual void takePicture();
};