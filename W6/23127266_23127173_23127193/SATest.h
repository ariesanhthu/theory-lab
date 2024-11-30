#pragma once
#include "ProgramFrame.h"
#include "ArrayAlgorithm.h"
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class SATest : public ProgramFrame {
    ArrayAlgorithm<T>* mAlg;
    vector<T> Data;

public:
    SATest(ArrayAlgorithm<T>* pAlg) : mAlg(pAlg) {}

    void Input(istream& is) override {
        cout << "Nhap so phan tu: ";
        int n;
        is >> n;
        Data.resize(n);
        cout << "Nhap cac phan tu: ";
        for (int i = 0; i < n; ++i) {
            is >> Data[i];
        }
    }

    bool Check() override {
        return !Data.empty();
    }

    void Output(ostream& os) override {
        os << "Mang sau khi sap xep: ";
        for (const T& item : Data) {
            os << item << " ";
        }
        os << "\n\n";
    }

    void startMessage(ostream& os) override {
        os << "Nhap vao kich thuoc va cac phan tu cua mang:\n";
    }

    void Process() override {
        if (mAlg != nullptr)
            mAlg->Process(Data);
    }
};
