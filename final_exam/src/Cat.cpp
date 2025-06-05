// File: Cat.cpp

#include "Cat.hpp"

Cat::Cat(std::string name, int age, int livesLeft) 
    : Animal(name, age), livesLeft(livesLeft) {}

// Getters
int Cat::getLivesLeft() { return livesLeft; }

void Cat::sayHi() {
    Animal::sayHi();
    
    std::stringstream extra_result;

    extra_result    << "I forgot, but I have " << livesLeft
                    << " lives left. Ouch!";

    std::cout << extra_result.str() << std::endl;
}

