#include "src/Camera.hpp"
#include "src/Computer.hpp"
#include "src/MobileDev.hpp"
#include "src/Smartphone.hpp"

int main() {
    Computer computer(16384, 4.0);
    computer.turnOn();
    
    Camera camera(4.0);
    camera.takePicture();

    MobileDev mobileDev("Nokia", 4.5);
    mobileDev.takePicture();
    mobileDev.takePicture(5);
    
    Smartphone smartphone("Samsung", 6.2, 8192, 3.0, 12.0, "Verizon");
    smartphone.takePicture();

    return 0;
}
