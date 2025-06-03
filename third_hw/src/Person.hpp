// File: Person.hpp

#pragma once

#include <string>
#include <sstream>

class Person {
    private:
        std::string name;
        int age;

    public:
        // Constructor
        Person(const std::string& name, int age);

        // Getters
        const std::string& get_name() const;
        const int get_age() const;

        // Parse from Person to String
        virtual std::string toString() const;

        // Destructor
        virtual ~Person();
};