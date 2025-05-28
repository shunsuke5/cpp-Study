#include "Inline.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
using namespace std;

inline int Bit(int x) {
    return 1 << x;
}

int main() {
    auto start = chrono::system_clock::now();
    for (int i = 0; i < 1000; i++) {
        cout << Bit(0) << endl;
    }
    auto end = chrono::system_clock::now();

    chrono::duration<double, milli> elapsed = end - start;
    cout << elapsed.count() << endl;

    Inline i;
    i.Print();
}