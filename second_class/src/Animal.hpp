// Animal.hpp

#pragma once
#include <string>
#include <iostream>

class Animal {
    private:
        int age;
        int weight;
        std::string name;

    public:
        Animal();
        Animal(int age, int weight, std::string name);
        
        void eat();
        int sum(int value1, int value2);

        ~Animal();
};