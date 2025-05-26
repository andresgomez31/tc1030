#pragma once
#include <iostream>

class Computer {
    private:
        int ramAmount;
        float cpuClockSpeed;

    public:
        Computer();
        Computer(int ramAmount, float cpuClockSpeed);
        void turnOn(){};
};