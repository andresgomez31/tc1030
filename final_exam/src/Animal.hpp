// File: Animal.hpp

#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Animal {
    private: 
        std::string name;
        int age;

    public:
        Animal(std::string name, int age);

        virtual void sayHi();

        // Getters
        std::string getName();
        int getAge();
};