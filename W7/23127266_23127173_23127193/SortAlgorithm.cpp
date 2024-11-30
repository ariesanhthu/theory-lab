#include "SortAlgorithm.h"
#include "Student.h"

// Constructor private
template <typename T>
SortAlgorithm<T>::SortAlgorithm() {
    currentAlgorithm = SelectionSort; // Thuật toán mặc định là Selection Sort
}

// Lấy đối tượng singleton và thiết lập thuật toán
template <typename T>
SortAlgorithm<T>* SortAlgorithm<T>::getObject(void (*pAlg)(T[], int)) {
    if (_algorithm == nullptr) {
        _algorithm = new SortAlgorithm<T>();
    }
    if (pAlg != nullptr) {
        _algorithm->currentAlgorithm = pAlg;
    }
    return _algorithm;
}

// Gọi thuật toán sắp xếp hiện tại
template <typename T>
void SortAlgorithm<T>::Sort(T a[], int n) {
    if (currentAlgorithm != nullptr) {
        currentAlgorithm(a, n);
    }
}

// Thuật toán Selection Sort
template <typename T>
void SortAlgorithm<T>::SelectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// Thuật toán Insertion Sort
template <typename T>
void SortAlgorithm<T>::InsertionSort(T a[], int n) {
    for (int i = 1; i < n; ++i) {
        T x = a[i];
        int pos = i;
        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            --pos;
        }
        a[pos] = x;
    }
}

// Thuật toán Interchange Sort
template <typename T>
void SortAlgorithm<T>::InterchangeSort(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

template class SortAlgorithm<char>;
template class SortAlgorithm<float>;
template class SortAlgorithm<string>;
template class SortAlgorithm<STUDENT>;