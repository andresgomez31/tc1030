// File: main.cpp

#include "src/Animal.hpp"
#include "src/Dog.hpp"
#include "src/Cat.hpp"
#include <vector>

int main() {
    // Creating vector with 3 cats and 3 dogs
    std::vector<Animal*> animals; 
    std::string name;
    std::string breed;

    // You can change this names as you want. I have no creative thoughs
    std::vector<std::string> names = {"Doge", "Firulais", "Solovino", "Solosefue", "Gato", "Rayas"};
    std::vector<int> ages = {4, 3, 5, 2, 1, 6};
    std::vector<std::string> breeds = {"Dobberman", "unknown", "Salchicha"};
    std::vector<int> livesLeft = {7, 7, 7};

    int total_animals = 0;

    for (int i = 0; i < breeds.size(); i++) {
        name = names[total_animals];
        breed = breeds[total_animals];
        animals.push_back(new Dog(name, ages[total_animals], breed));
        total_animals++;
    }
    for (int i = 0; i < livesLeft.size(); i++) {
        name = names[total_animals];
        animals.push_back(new Cat(name, ages[total_animals], livesLeft[i]));
        total_animals++;
    }

    // Saying Hi in all animals:
    for (const auto& animal : animals) animal->sayHi();

    return 0;
}

/**
 * What polymorphism is?
 * 
 * Is a feature on OOP that allows objects have different behavior while sharing the same parent class. 
 * 
 * So, it is useful when you have similar objects that have different behavior but in fact, performs the same action. 
 * Also, is useful to store objects on vector, matrix, maps, etc. that are different between them but all of them are derivate from the
 * same class.
 * 
 * Here is applied to iterate trough the vector 'animals' and call a shared polymorphic method, 'sayHi()'. 
 */