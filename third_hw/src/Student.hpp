// File: Student.hpp

#pragma once

#include "Person.hpp"

class Student : public Person {
    private:
        std::string enrollment_id;

    public:
        // Constructor method
        Student(const std::string& name, int age, const std::string& enrollment_id);

        // Getter for enrollment_id
        const std::string& get_enrollment_id() const;

        // Parse from Student to String
        std::string toString() const override;

        // Destructor method
        ~Student();
};