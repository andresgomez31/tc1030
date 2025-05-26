// File: Computer.hpp

#pragma once
#include <iostream>

class Computer {
    private:
        int ramAmount;
        float cpuClockSpeed;

    public:
        Computer();
        Computer(int ramAmount, float cpuClockSpeed);

        int getRamAmount();
        float getCpuClockSpeed();

        void turnOn();
};