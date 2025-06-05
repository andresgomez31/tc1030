// File: Dog.cpp

#include "Dog.hpp"

Dog::Dog(std::string name, int age, std::string breed) 
    : Animal(name, age), breed(breed) {}

// Getters
std::string Dog::getBreed() { return breed; }

void Dog::sayHi() {
    std::stringstream result;

    result  << "Hi! My name is " << getName()
            << ", i'm " << getAge()
            << " years old, and my breed is '" << getBreed() << "'.";

    std::cout << result.str() << std::endl;
}
