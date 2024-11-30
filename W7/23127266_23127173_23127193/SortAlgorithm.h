#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SortAlgorithm {
private:
    static SortAlgorithm<T>* _algorithm;               // Con trỏ singleton
    void (*currentAlgorithm)(T[], int);               // Con trỏ hàm lưu thuật toán hiện tại
    SortAlgorithm();                                   // Constructor private (singleton)

public:
    static SortAlgorithm<T>* getObject(void (*pAlg)(T[], int) = nullptr); 
    static void SelectionSort(T a[], int n);         
    static void InsertionSort(T a[], int n);         
    static void InterchangeSort(T a[], int n);       
    void Sort(T a[], int n);                  
};

// Khai báo con trỏ static cho lớp SortAlgorithm
template <typename T>
SortAlgorithm<T>* SortAlgorithm<T>::_algorithm = nullptr;

// Bao gồm định nghĩa template
//#include "SortAlgorithm.cpp" 
