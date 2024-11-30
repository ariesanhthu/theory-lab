#pragma once
#include <string>
#include <iostream>

using namespace std;

class STUDENT {
public:
    string name;
    float grade;

    STUDENT(string name, float grade) : name(name), grade(grade) {}

    bool operator<(const STUDENT& other) const;
    bool operator>(const STUDENT& other) const;

    friend ostream& operator<<(ostream& os, const STUDENT& student);
};
