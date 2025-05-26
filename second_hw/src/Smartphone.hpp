// File: Smartphone.hpp

#pragma once
#include "MobileDev.hpp"

class Smartphone : public MobileDev {
    private:
        std::string carrier;

    public:
        Smartphone();
        Smartphone(std::string carrier);
        Smartphone(std::string brand, float screenSize, int ramAmount, float cpuClockSpeed, float lensSize, std::string carrier);
        
        void takePicture() override;
};