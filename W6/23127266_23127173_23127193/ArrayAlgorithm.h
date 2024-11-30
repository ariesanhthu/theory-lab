#pragma once
#include <vector>
using namespace std;

template <typename T>

class ArrayAlgorithm {
public:
    virtual void Process(vector<T>& arr) = 0;
    virtual ~ArrayAlgorithm() = default;
};
