// File: Smartphone.cpp

#include "Smartphone.hpp"
#include <limits>

Smartphone::Smartphone() : carrier("unavailable") {}

Smartphone::Smartphone(std::string carrier) : carrier(carrier) {}

Smartphone::Smartphone(std::string brand, float screenSize, int ramAmount, float cpuClockSpeed, float lensSize, std::string carrier)
    : MobileDev(brand, screenSize, ramAmount, cpuClockSpeed, lensSize), carrier(carrier) {}

void Smartphone::takePicture() {
    int countdown = -1;

    while (true) {
        std::cout << "Enter the picture timer as an integer: ";
        std::string input;
        std::getline(std::cin, input);

        try {
            countdown = std::stoi(input);
            if (countdown < 0) {
                std::cout << "Countdown must be a positive integer." << std::endl;
                continue;
            }
            break;
        }
        catch (const std::exception&) {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }

    MobileDev::takePicture(countdown);
    std::cout << "Picture taken with phone carrier: " << carrier << std::endl;
}
