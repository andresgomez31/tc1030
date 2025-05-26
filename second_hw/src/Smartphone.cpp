#include "Smartphone.hpp"

Smartphone::Smartphone() : carrier("unavailable") {}

Smartphone::Smartphone(std::string carrier) : carrier(carrier) {}

void Smartphone::takePicture() {
    std::string input;
    int countdown = -1;

    do {
        std::cout << "Enter the picture timer as an integer: ";
        std::cin >> input;

        try {
            countdown = std::stoi(input);
            if (countdown < 0) {
                std::cout << "Countdown must be a positive integer." << std::endl;
                continue;
            }
        }
        catch (const std::exception&) {
            std::cout << "Invalid input. Try again." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            countdown = -1;
            continue;
        }
    }
    while (countdown < 0);

    takePicture(countdown);
    std::cout << "Picture taken with phone carrier: " << carrier << std::endl;
}