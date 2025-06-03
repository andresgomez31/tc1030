// File: Teacher.hpp

#pragma once

#include "Person.hpp"

class Teacher : public Person {
    private:
        std::string teacher_id;

    public:
        // Constructor method
        Teacher(const std::string& name, int age, const std::string& teacher_id);

        // Getter for teacher_id
        const std::string& get_teacher_id() const;

        // Parse from Teacher to String
        std::string toString() const override;

        // Destructor method
        ~Teacher();
};