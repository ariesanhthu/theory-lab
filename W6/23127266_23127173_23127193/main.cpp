#include "SelectionSort.h"
#include "InsertionSort.h"
#include "Interchange.h"
#include "SATest.h"
#include <iostream>
#include <string>

using namespace std;

void printMenu()
{
    cout << "================================\n";
    cout << "Nhap chuc nang can test: \n";
    cout << "0. Thoat chuong trinh!\n";
    cout << "1. Short test\n";
    cout << "2. Double test\n";
    cout << "3. String test\n";
}

void printMenuAlgo()
{
    cout << "================================\n";
    cout << "Chon thuat toan can test: \n";
    cout << "0. Thoat khoi lua chon!\n";
    cout << "1. Selection sort \n";
    cout << "2. Insertion sort \n";
    cout << "3. Interchange sort \n";
}

template <class T>
void Test(SATest<T>& saTest)
{
    printMenuAlgo();
    int optionAlgo;

    cout << "Nhap lua chon cua ban: ";
    cin >> optionAlgo;

    switch (optionAlgo)
    {
    case 1:
        saTest = SATest<T>(new SelectionSort<T>());
        break;
    case 2:
        saTest = SATest<T>(new InsertionSort<T>());
        break;
    case 3:
        saTest = SATest<T>(new InterchangeSort<T>());
        break;
    default:
        cout << "Thoat khoi lua chon\n";
        return;
    }
    saTest.run(cin, cout);
}

int main() {
    int option;

    while (true)
    {
        printMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            SATest<short> saTest(nullptr);
            Test(saTest);
            break;
        }
        case 2:
        {
            SATest<double> saTest(nullptr);
            Test(saTest);
            break;
        }
        case 3:
        {
            SATest<string> saTest(nullptr);
            Test(saTest);
            break;
        }
        case 0:
            cout << "Ket thuc chuong trinh!\n";
            return 0;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    }

    return 0;
}
