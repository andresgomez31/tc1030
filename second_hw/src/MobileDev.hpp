#pragma once
#include "Camera.hpp"
#include "Computer.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <thread>

class MobileDev : public Camera, public Computer {
    private: 
        std::string brand;
        float screenSize;
        std::string getSpecs();

    public:
        MobileDev();
        MobileDev(std::string brand, float screenSize);

        virtual void takePicture() override;

        virtual void takePicture(int countdown);
};