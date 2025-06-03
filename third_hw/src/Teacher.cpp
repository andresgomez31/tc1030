// File: Teacher.cpp

#include "Teacher.hpp"

Teacher::Teacher(const std::string& name, int age, const std::string& teacher_id) 
    : Person(name, age), teacher_id(teacher_id) {}

const std::string& Teacher::get_teacher_id() const {
    return teacher_id;
}

std::string Teacher::toString() const {
    std::ostringstream result;
    result << "Teacher: " << get_name() << ", Age: " << get_age() 
    << ", Teacher ID: " << get_teacher_id();
    return result.str(); 
}

Teacher::~Teacher() {}