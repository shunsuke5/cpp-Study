#include "Fraction.hpp"
#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

void Hoge(int* cp) {
    int* p = (int*)cp;
}

int main() {
    // static_cast
    signed char a = -1;
    int b;

    b = a;
    printf("%08X (%d)\n", b, b);

    b = static_cast<unsigned char>(a);
    printf("%08X (%d)\n", b, b);

    // reinterpret_cast
    int n = 0x12345678;
    const char* p = reinterpret_cast<const char*>(&n);

    for (size_t i = 0; i < sizeof n; ++i) {
        printf("%02X", p[i]);
    }
    printf("<-> %08X\n", n);

    // const_cast
    const int n2 = 1;
    const int* p2 = &n2;
    Hoge(const_cast<int*>(p2));
}