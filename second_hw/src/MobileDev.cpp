#include "MobileDev.hpp"

MobileDev::MobileDev() {}

MobileDev::MobileDev(std::string brand, float screenSize) : brand(brand), screenSize(screenSize) {}

std::string MobileDev::getSpecs() {
    std::stringstream specs;
    specs << brand << " mobile device with " << 
    std::fixed << std::setprecision(1) << screenSize << " inch screen.";

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
        std::cout << seconds << "... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
    }
    takePicture();
}
