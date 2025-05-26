// File: MobileDev.cpp

#include "MobileDev.hpp"

MobileDev::MobileDev() : Camera(), Computer() {}

MobileDev::MobileDev(std::string brand, float screenSize) 
    : brand(brand), screenSize(screenSize) {}

MobileDev::MobileDev(std::string brand, float screenSize, int ramAmount, float cpuClockSpeed, float lensSize)
    : Camera(lensSize), Computer(ramAmount, cpuClockSpeed), brand(brand), screenSize(screenSize) {}

std::string MobileDev::getSpecs() {
    std::stringstream specs;
    specs << brand << " mobile device.\n\t" << 
    std::fixed << std::setprecision(1) << screenSize << " inch screen.\n\t" <<
    "DRAM (MB): " << Computer::getRamAmount() << "\n\t" <<
    "CPU CLOCK SPEED (GHZ): " << Computer::getCpuClockSpeed() << "\n\t" <<
    "Lens size (mm): " << Camera::getLensSize();

    return specs.str();
}

void MobileDev::takePicture() {
    std::time_t timestamp = std::time(nullptr);
    std::cout << "Picture taken at " << std::asctime(std::localtime(&timestamp))
    << "\n\tDevice: " << getSpecs() << std::endl;
}

void MobileDev::takePicture(int countdown) {
    int seconds = countdown;

    while (seconds > 0) {
        std::cout << seconds << "... " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
    }
    MobileDev::takePicture();
}
