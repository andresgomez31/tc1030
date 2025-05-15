#include "Animal.hpp"

Animal::Animal() : age(0), weight(0), name("") {}
Animal::Animal(int age, int weight, std::string name) : age(age), weight(weight), name(name) {}

void Animal::eat(){
    std::cout << "The animal is eating. Ñom ñom " << std::endl;
}

int Animal::sum(int value1, int value2) {
    return value1 + value2;
}

Animal::~Animal(){
    
}