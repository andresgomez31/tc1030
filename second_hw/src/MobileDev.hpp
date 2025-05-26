// File: MobileDev.hpp

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

    protected:
        std::string getSpecs();

    public:
        MobileDev();
        MobileDev(std::string brand, float screenSize);
        MobileDev(std::string brand, float screenSize, int ramAmount, float cpuClockSpeed, float lensSize);

        virtual void takePicture() override;

        virtual void takePicture(int countdown);
};