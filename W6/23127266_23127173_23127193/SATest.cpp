#include "SATest.h"
#include <vector>

using namespace std;

template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    int n;
    is >> n;
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        is >> vec[i];
    }
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (const T& val : vec) {
        os << val << " ";
    }
    return os;
}