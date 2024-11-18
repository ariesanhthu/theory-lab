#pragma once
#include <iostream>
#include "SortAlgo.h"

using namespace std;

int main() {

    float arr[] = { 2.4F, 3.4F, 1.4F, 5.4F, 4.4F };
    int n = sizeof(arr) / sizeof(arr[0]);

    //---------------------------------------------

    cout << "BUBBLE SORT: \n";
    
    SortAlg::setAlg(SortAlg::bubbleSort);
    SortAlg::Sort(arr, n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";

    cout << "\n\n";

    //---------------------------------------------

    cout << "INTERCHANGE SORT: \n"; 

    SortAlg::setAlg(SortAlg::interchangeSort);
    SortAlg::Sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\n";
    
    //---------------------------------------------

    cout << "SELECTION SORT: \n";

    SortAlg::setAlg(SortAlg::selectionSort);
    SortAlg::Sort(arr, n);

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    
    cout << "\n\n";
    
    return 0;
}