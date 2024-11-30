#include <iostream>
#include <fstream>
#include "CMessage.h"
#include "utils.h"

using namespace std;
using namespace utils;

int main() {
    std::cout << "Check the result in input.txt and output.txt\n";

    CMessage* mes = new CMessage(); 
    
    wifstream fin("input.txt", ios::binary);
    if (!utils::isExistFile("input.txt")) {
        wcerr << L"Failed to open the file: ";
        delete mes;
        exit(1);
    }
    wofstream fout("output.txt", ios::binary);
    if (!utils::isExistFile("output.txt")) {
        wcerr << L"Failed to open the file: ";
        delete mes;
        exit(1);
    }

    mes->finput(fin);
    mes->foutput(fout);

    delete mes;
    fin.close();
    fout.close();

    return 0;
}



