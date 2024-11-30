#pragma once
#include "ArrayAlgorithm.h"
#include <iostream>

template <class T>
class InterchangeSort : public ArrayAlgorithm<T> {
public:
    void Process(vector<T>& data) override {
        for (size_t i = 0; i < data.size() - 1; ++i) {
            for (size_t j = i + 1; j < data.size(); ++j) {
                if (data[j] < data[i])
                    swap(data[i], data[j]);
            }
        }
    }
};
