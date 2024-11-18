#pragma once
#include "SortAlgo.h"
#include "iostream"

using namespace std;

void swap(float& a, float& b)
{
    float tmp = a;
    a = b;
    b = tmp;
}

void (*SortAlg::currentAlg)(float[], int) = SortAlg::interchangeSort;

void SortAlg::setAlg(void(*pAlg)(float[], int)) 
{ 
    if (pAlg) 
        currentAlg = pAlg; 
}

void SortAlg::interchangeSort(float arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void SortAlg::bubbleSort(float arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SortAlg::selectionSort(float arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void SortAlg::Sort(float arr[], int n) 
{ 
    if (currentAlg) 
        currentAlg(arr, n); 
}
