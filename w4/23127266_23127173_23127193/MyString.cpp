#include "MyString.h"

// Constructor
MyString::MyString(const MyString& other) {
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        str[i] = other.str[i];
    str[size] = '\0';
}

MyString::MyString(const char* s)
{
    set(s);
}

// Destructor
MyString::~MyString() {
    if (str)
        delete[]str;
}

int MyString::length() const {
    return size;
}

void MyString::set(int newSize) {
    if (newSize < 0) {
        cout << "invalid size" << endl;
        exit(1);
    }
    if (newSize == size) return;

    char* res = new char[newSize + 1];

    if (newSize > size) {
        for (int i = 0; i < size; i++)
            res[i] = str[i];
        for (int i = size; i < newSize; i++)
            res[i] = '\0';
        res[newSize] = '\0';
    }
    else if (newSize < size) {
        for (int i = 0; i < newSize; i++)
            res[i] = str[i];
    }
    delete[] str;
    str = res;
    size = newSize;
}

void MyString::set(const char* newChar) {
    size = 0;
    while (newChar[size] != '\0')
        size++;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
        str[i] = newChar[i];
    str[size] = '\0';
}

char* MyString::subString(int index, int number)
{
    if (index < 0 || index > size)
    {
        cout << "invalid index" << endl;
        return NULL;
    }

    if (number < 0)
    {
        cout << "invalid number" << endl;
        return NULL;
    }

    char* res = new char[number + 1];
    for (int i = 0; i < number; i++)
        res[i] = str[index + i];
    res[number] = '\0';
    return res;
}
bool MyString::insert(int index, const char* insertStr)
{
    if (index < 0 || index > size)
    {
        cout << "invalid index" << endl;
        return false;
    }

    if (insertStr == NULL)
    {
        cout << "invalid insertStr" << endl;
        return false;
    }

    int sizeInsertStr = 0;
    while (insertStr[sizeInsertStr] != '\0')
        sizeInsertStr++;

    char* res = new char[size + sizeInsertStr + 1];

    for (int i = 0; i < index; i++)
        res[i] = str[i];

    for (int i = 0; i < sizeInsertStr; i++)
        res[index + i] = insertStr[i];

    for (int i = index; i < size; i++)
        res[i + sizeInsertStr] = str[i];

    res[size + sizeInsertStr] = '\0';

    size += sizeInsertStr;

    delete[] str;
    str = res;

    return true;
}


bool MyString::erase(int index, int number)
{
    if (index < 0 || index > size)
    {
        cout << "invalid index" << endl;
        return false;
    }

    if (number < 0)
    {
        cout << "invalid number" << endl;
        return false;
    }

    if (index + number > size)
    {
        cout << "invalid number" << endl;
        return false;
    }

    char* res = new char[size - number + 1];

    for (int i = 0; i < index; i++)
        res[i] = str[i];

    for (int i = index + number; i < size; i++)
        res[i - number] = str[i];

    res[size - number] = '\0';
    size -= number;

    delete[] str;
    str = res;

    return true;
}

bool MyString::replace(int index, int number, const char* replaceStr)

{
    if (index < 0 || index > size)
    {
        cout << "invalid index" << endl;
        return false;
    }

    if (number < 0)
    {
        cout << "invalid number" << endl;
        return false;
    }

    if (index + number > size)
    {
        cout << "invalid number" << endl;
        return false;
    }

    if (replaceStr == NULL)
    {
        cout << "invalid replaceStr" << endl;
        return false;
    }

    int replaceStrSize = 0;
    while (replaceStr[replaceStrSize] != '\0')
        replaceStrSize++;

    char* res = new char[size + replaceStrSize - number + 1];

    for (int i = 0; i < index; i++)
        res[i] = str[i];

    for (int i = 0; i < replaceStrSize; i++)
        res[i + index] = replaceStr[i];

    for (int i = index + number; i < size; i++)
        res[i + replaceStrSize - number] = str[i];

    res[size + replaceStrSize - number] = '\0';
    size += replaceStrSize - number;

    delete[] str;
    str = res;

    return true;
}

int MyString::find(int index, const char* findStr)
{
    if (index < 0 || index > size)
    {
        cout << "invalid index" << endl;
        return -1;
    }

    if (findStr == NULL)
    {
        cout << "invalid findStr" << endl;
        return -1;
    }

    int findStrSize = 0;
    while (findStr[findStrSize] != '\0')
        findStrSize++;

    int count = 0;

    for (int i = index; i < size - findStrSize + 1; i++)
    {
        for (int j = 0; j < findStrSize; j++)
        {
            if (findStr[j] != str[i + j])
                break;
            else if (j == findStrSize - 1)
                count++;
        }
    }

    return count;
}

MyString MyString::operator+(const char* t) const
{
    int tSize = 0;
    while (t[tSize] != '\0')
        tSize++;

    MyString res;
    res.str = new char[size + tSize + 1];

    for (int i = 0; i < size; i++)
        res.str[i] = str[i];

    for (int i = 0; i < tSize; i++)
        res.str[i + size] = t[i];

    res.str[size + tSize] = '\0';
    res.size = size + tSize;

    return res;
}

MyString MyString::operator+(const MyString& t) const
{
    int tSize = t.size;

    MyString res;

    res.str = new char[size + tSize + 1];

    for (int i = 0; i < size; i++)
        res.str[i] = str[i];

    for (int i = 0; i < tSize; i++)
        res.str[i + size] = t.str[i];

    res.str[size + tSize] = '\0';
    res.size = size + tSize;

    return res;
}

bool MyString::operator > (const MyString& src) const {
    int len = (src.size > this->size ? this->size : src.size);
    bool check = true;
    for (int i = 0; i < len; i++)
        if (this->str[i] != src.str[i])
            return (this->str[i] > src.str[i]);
    return (this->size > src.size);
}
bool MyString::operator >= (const MyString& src) const {
    int len = (src.size > this->size ? this->size : src.size);
    bool check = true;
    for (int i = 0; i < len; i++)
        if (this->str[i] != src.str[i])
            return (this->str[i] > src.str[i]);
    return (this->size >= src.size);
}

bool MyString::operator < (const MyString& src) const {
    return !(*this >= src);
}

bool MyString::operator <= (const MyString& src) const {
    return !(*this > src);
}

char MyString::operator[](const int& index) {
    if (index < 0 || index >= size)
    {
        cout << "Chi so vuot qua gioi han chuoi!\n";
        exit(1);
    }
    return str[index];
}

bool MyString::operator==(const MyString& t) {
    if (this == &t) return true;

    int len = t.size;

    if (size != len) return false;

    for (int i = 0; i < len; i++) {
        if (str[i] != t.str[i]) return false;
    }

    return true;
}
bool MyString::operator!=(const MyString& t) {
    return !(*this == t);
}
MyString& MyString::operator=(const MyString& t) {
    if (this != &t) {
        delete[] str;
        size = t.size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            str[i] = t.str[i];
        }
        str[size] = '\0';
    }
    return *this;
}


// overloading cin cout

// input
istream& operator>>(istream& inDev, MyString& s)
{
    char temp[1000];
    inDev >> temp;

    int length = 0;

    while (temp[length] != '\0')
        length++;

    delete[] s.str;
    s.str = new char[length + 1];

    for (int i = 0; i < length; i++)
        s.str[i] = temp[i];

    s.str[length] = '\0';
    s.size = length;

    return inDev;
}

// output
ostream& operator<<(ostream& outDev, const MyString& s)
{
    for (int i = 0; i < s.size; i++)
        outDev << s.str[i];
    return outDev;
}