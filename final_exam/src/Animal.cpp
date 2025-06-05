// File: Animal.cpp

#include "Animal.hpp"

Animal::Animal(std::string name, int age)
    : name(name), age(age) {}

// Getters
std::string Animal::getName() { return name; }
int Animal::getAge() { return age; }

void Animal::sayHi() {
    std::stringstream result;

    result  << "Hi! My name is " << getName()
            << " and i'm " << getAge()
            << " years old. ";

    std::cout << result.str() << std::endl;
}