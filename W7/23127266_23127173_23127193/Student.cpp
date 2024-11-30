#pragma once
#include "Student.h"
#include <string>
#include <iostream>

using namespace std;

bool STUDENT::operator<(const STUDENT& other) const 
{
        return grade < other.grade;
}

bool STUDENT::operator>(const STUDENT& other) const 
{
        return grade > other.grade;
}

ostream& operator<<(ostream& os, const STUDENT& student) 
{
        os << "Name: " << student.name << ", Grade: " << student.grade;
        return os;
}
