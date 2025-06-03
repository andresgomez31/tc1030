// File: main.cpp

#include <iostream>
#include <vector>
#include "src/Person.hpp"
#include "src/Student.hpp"
#include "src/Teacher.hpp"
#include "menu.hpp"

int main () {
    std::vector<Person*> people;
    menu(people);
    free_memory(people);
    return 0;
}