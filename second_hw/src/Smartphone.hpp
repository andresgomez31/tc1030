#include "MobileDev.hpp"

class Smartphone : public MobileDev {
    private:
        std::string carrier;

    public:
        Smartphone();
        Smartphone(std::string carrier);

        void takePicture() override;
};