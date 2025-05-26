// File: Computer.cpp

#include "Computer.hpp"

Computer::Computer() 
    : ramAmount(8192), cpuClockSpeed(3.3) {}

Computer::Computer(int ramAmount, float cpuClockSpeed) 
    : ramAmount(ramAmount), cpuClockSpeed(cpuClockSpeed) {}

int Computer::getRamAmount() {
    return ramAmount;
}

float Computer::getCpuClockSpeed() {
    return cpuClockSpeed;
}

void Computer::turnOn() {
    std::cout << "Computer specs: \n\tDRAM (MB): " << ramAmount << "\n\tCPU CLOCK SPEED (GHZ): " << cpuClockSpeed << std::endl;
};