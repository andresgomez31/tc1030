// File: Person.cpp

#include "Person.hpp"

Person::Person(const std::string& name, int age) : name(name), age(age) {}

const std::string& Person::get_name() const {
    return name;
}

const int Person::get_age() const {
    return age;
}

std::string Person::toString() const {
    std::ostringstream result;
    result << "Name: " << name << ", Age: " << age;
    return result.str();
}

Person::~Person() {} 