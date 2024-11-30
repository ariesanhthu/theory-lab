#include "SortAlgorithm.h"
#include "Student.h"
#include <string>

using namespace std;

int main() {
    // Kiểu float
    float a[] = { 1.4F, -5.2F, 3.3F, 0 };
    int n = sizeof(a) / sizeof(a[0]);

    SortAlgorithm<float>* algFloat = SortAlgorithm<float>::getObject(SortAlgorithm<float>::InterchangeSort);
    algFloat->Sort(a, n);
    
    cout << "Mang floats sau khi sap xep:" << endl;
    
    for (int i = 0; i < n; ++i) 
    {
        cout << a[i] << "\t";
    }
    
    cout << endl;

    // Kiểu char
    char b[] = { 'A', 'B', 'C', 'D' };
    n = sizeof(b) / sizeof(b[0]);
    
    SortAlgorithm<char>* algChar = SortAlgorithm<char>::getObject(SortAlgorithm<char>::SelectionSort);
    
    algChar->Sort(b, n);
    
    cout << "Mang chars sau khi sap xep:" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << b[i] << "\t";
    }
    cout << endl;

    // Kiểu string
    string c[] = { "ABC", "CDB", "EFC", "SPZ" };
    
    n = sizeof(c) / sizeof(c[0]);
    
    SortAlgorithm<string>* algString = SortAlgorithm<string>::getObject(SortAlgorithm<string>::InsertionSort);
    
    algString->Sort(c, n);
    
    cout << "Mang strings sau khi sap xep:" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << c[i] << "\t";
    }
    cout << endl;

    // Kiểu STUDENT
    STUDENT d[] = { STUDENT("abc", 8.5), STUDENT("def", 9.5) , STUDENT("def", 5)};
    
    n = sizeof(d) / sizeof(d[0]);
    
    SortAlgorithm<STUDENT>* algStudent = SortAlgorithm<STUDENT>::getObject(SortAlgorithm<STUDENT>::SelectionSort);
    
    algStudent->Sort(d, n);
    
    cout << "Mang STUDENT sau khi sap xep:" << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << d[i] << endl;
    }

    return 0;
}
