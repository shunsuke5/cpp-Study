#include "Array.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    Array<int> iarray(5);
    Array<double> darray(5);
    Array<string> sarray(5);

    for (int i = 0, size = iarray.Size(); i < size; i++) {
        iarray.Set(i, i * 2);
        darray.Set(i, i * 5.5);
        sarray.Set(i, "亀井俊輔");
    }

    for (int i = 0, size = iarray.Size(); i < size; i++) {
        cout << iarray.Get(i) << ' ';
        cout << darray.Get(i) << ' ';
        cout << sarray.Get(i) << ' ';
        cout << endl;
    }
    cout << endl;
}