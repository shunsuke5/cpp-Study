#include "Fraction.hpp"
#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int Bit(int x) {
    return 1 << x;
}

const int SHOW_X = Bit(0);
const int SHOW_Y = Bit(1);
const int SHOW_Z = Bit(2);

void Show(int flags) {
    cout << ((flags & SHOW_X) != 0 ? 'X' : 'x')
        << ((flags & SHOW_Y) != 0 ? 'Y' : 'y')
        << ((flags & SHOW_Z) != 0 ? 'Z' : 'z')
        << endl;
}

int main() {
    Show(0);                        // xyz
    Show(SHOW_Y);                   // xYz
    Show(SHOW_X | SHOW_Z);          // XyZ
    Show(SHOW_X | SHOW_Y | SHOW_Z); // XYZ

    int flags = 0;
    // ビットフラグ追加
    cout << (flags |= (SHOW_X | SHOW_Y)) << endl;   // 3

    // ビットフラグ削除
    cout << (flags &= ~(SHOW_X | SHOW_Y)) << endl;  // 0

    // ビットフラグ反転
    cout << (flags ^= (SHOW_X | SHOW_Y)) << endl;   // 3
    cout << (flags ^= (SHOW_X | SHOW_Y)) << endl;   // 0
}