#include "InsertionSort.h"

template <class T>
void InsertionSort<T>::Process(std::vector<T>& data) {
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
