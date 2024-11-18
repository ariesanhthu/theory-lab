#pragma once
#include <iostream>

using namespace std;

class MyString
{
    char* str;
    int size;
public:

    MyString(const MyString& other);

    MyString() : str(nullptr), size(0) {}

    MyString(const char* s);

    ~MyString();

    int length()const;

    void set(int newSize);
    void set(const char* newChar);

    char* getStr()
    {
        return str;
    }

    char* subString(int index, int number);

    bool insert(int index, const char* insertStr);

    bool erase(int index, int number);

    bool replace(int index, int number, const char* replaceStr);

    int find(int index, const char* findStr);

    MyString operator+(const char* t) const;

    MyString operator+(const MyString& t) const;

    bool operator > (const MyString& src) const;

    bool operator >= (const MyString& src) const;

    bool operator < (const MyString& src) const;

    bool operator <= (const MyString& src) const;

    char operator[](const int& index);

    bool operator==(const MyString& t);

    bool operator!=(const MyString& t);

    MyString& operator=(const MyString& t);

    friend istream& operator>>(istream& inDev, MyString& s);
    friend ostream& operator<<(ostream& outDev, const MyString& s);
};