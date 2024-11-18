#pragma once
#include "ArrayAlgorithm.h"

template <class T>
class SelectionSort : public ArrayAlgorithm<T> {
public:
    void Process(vector<T>& data) override {
        for (int i = 0; i < data.size() - 1; ++i) {
            int minIdx = i;
            for (int j = i + 1; j < data.size(); ++j) {
                if (data[j] < data[minIdx])
                    minIdx = j;
            }
            if (minIdx != i)
                swap(data[i], data[minIdx]);
        }
    }
};
