#include "src/Camera.hpp"
#include "src/Computer.hpp"
#include "src/MobileDev.hpp"
#include "src/Smartphone.hpp"

int main() {
    Camera camera(4.0);

    Computer computer(16384, 4.0);

    MobileDev mobileDev("Nokia", 4.5);

    Smartphone smartphone("Samsung", 6.2, 8192, 3.0, 12.0, "Telcel");

    camera.takePicture();

    computer.turnOn();

    mobileDev.takePicture();
    mobileDev.takePicture(5);

    smartphone.takePicture();
}