// File: menu.cpp

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "src/Person.hpp"
#include "src/Student.hpp"
#include "src/Teacher.hpp"

void append_person(std::vector<Person*>& people, Person* value) {
    people.push_back(value);
}

void print_all_people(std::vector<Person*>& people) {
    for (const auto& _ : people) {
        std::cout << _->toString() << std::endl;    
    }
}

void add_student(std::vector<Person*>& people) {
    std::string name, enrollment_id;
    int age;
    
    std::cout << "Type the student's name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Now, their age: ";
    std::cin >> age;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try with a positive integer for age: ";
        std::cin >> age;
    }

    std::cout << "Finally, assign their Enrollment ID: ";
    std::cin.ignore();
    std::getline(std::cin, enrollment_id);

    append_person(people, new Student(name, age, enrollment_id));
}

void add_teacher(std::vector<Person*>& people) {
    std::string name, teacher_id;
    int age;
    
    std::cout << "Type the teacher's name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Now, their age: ";
    std::cin >> age;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try with a positive integer for age: ";
        std::cin >> age;
    }

    std::cout << "Finally, assign their Teacher ID: ";
    std::cin.ignore();
    std::getline(std::cin, teacher_id);

    append_person(people, new Teacher(name, age, teacher_id));
}

void free_memory(std::vector<Person*>& people) {
    for (Person* _ : people) {
        delete _;
    }
    people.clear();
}

void menu(std::vector<Person*>& people) {
    int input;
    do {
        std::cout << "Welcome. Select an option to continue: " << std::endl;
        std::cout << "\t1) Add a student." << std::endl;
        std::cout << "\t2) Add a teacher. " << std::endl;
        std::cout << "\t3) Print everyone. " << std::endl;
        std::cout << "\t9) Exit. " << std::endl;

        std::cin >> input;

        switch (input) {
            case 1: 
                add_student(people);
                break;
            
            case 2:
                add_teacher(people);
                break;
            case 3:
                print_all_people(people);
                break;
            case 9:
                free_memory(people);
                break;
            default:
                std::cout << "Not a valid option. Try again with 1, 2, 3 or 9. " << std::endl;
        }
        std::cin.clear();
    }
    while (input != 9);
}
