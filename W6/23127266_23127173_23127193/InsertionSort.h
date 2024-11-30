#pragma once
#include "ArrayAlgorithm.h"

template <class T>
class InsertionSort : public ArrayAlgorithm<T> {
public:
    void Process(vector<T>& data) override {
        for (int i = 1; i < data.size(); ++i) {
            T key = data[i];
            int j = i;
            while (j > 0 && data[j - 1] > key) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = key;
        }
    }
};
