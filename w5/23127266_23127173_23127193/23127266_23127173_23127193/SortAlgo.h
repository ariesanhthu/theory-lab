#pragma once

class SortAlg {
private:
    // static SortAlg * obj;
    SortAlg() {}
    static void (*currentAlg)(float[], int);
public:
    // static SortAlg* getInstance(void(*pAlg)(float[], int) = NULL);

    static void interchangeSort(float arr[], int n);
    static void bubbleSort(float arr[], int n);
    static void selectionSort(float arr[], int n);
    static void setAlg(void(*pAlg)(float[], int));
    static void Sort(float[], int);
};

