// File: menu.hpp

#pragma once
#include <vector>
#include "src/Person.hpp"

void append_person(std::vector<Person*>& people, Person* value);
void print_all_people(const std::vector<Person*>& people);
void add_student(std::vector<Person*>& people);
void add_teacher(std::vector<Person*>& people);
void free_memory(std::vector<Person*>& people);
void menu(std::vector<Person*>& people);
