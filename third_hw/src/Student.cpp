// File: Student.cpp

#include "Student.hpp"

Student::Student(const std::string& name, int age, const std::string& enrollment_id)
    : Person(name, age), enrollment_id(enrollment_id) {}

const std::string& Student::get_enrollment_id() const {
    return enrollment_id;
}

std::string Student::toString() const {
    std::ostringstream result;
    result << "Student: " << get_name() << ", Age: " << get_age() 
        << ", Enrollment ID: " << enrollment_id;
    return result.str();
}

Student::~Student() {}
