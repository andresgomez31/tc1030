// File: Dog.hpp

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    private:
        std::string breed;

    public:
        Dog(std::string name, int age, std::string breed);
        
        void sayHi() override;

        // Getters:
        std::string getBreed();
};