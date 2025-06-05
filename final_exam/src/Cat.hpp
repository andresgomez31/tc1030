// File: Cat.hpp

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    private:
        int livesLeft;

    public:
        Cat(std::string name, int age, int livesLeft);

        void sayHi() override;

        // Getters
        int getLivesLeft();
};