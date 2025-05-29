#include "Inline.hpp"
#include <fstream>
#include <iostream>
#include "Calculator.hpp"
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    Calculator calc;
    calc.Run();

    int n = 0;

    /*
    * 普通のポインタ型の場合
    * constの位置によって、参照先かポインタ自身のどちらかが定数になる
    */

    const int* p1 = &n;     // 参照先の値がconst
    int* const q1 = &n;     // ポインタ自身がconst

    p1 = &n;
    q1 = &n;                // q1 はここでエラー
    *p1 = 1;                // p1 はここでエラー
    *q1 = 2;

    /*
    * ポインタ型の同義語の場合
    * constの位置に関わらず、ポインタ自身のみが定数になる
    */

    typedef int* IntPtr;

    const IntPtr p2 = &n;   // 参照先の値がconst...?(ではない)
    IntPtr const q2 = &n;   // ポインタ自身がconst

    p2 = &n;                // p2 もここでエラー
    q2 = &n;                // q2 はここでエラー
    *p2 = 1;
    *q2 = 2;

    /*
    * 同義語を用いて参照先をconstにしたい場合、
    * 同義語の宣言でconstを使用する
    */

    typedef const int* IntCptr;

    IntCptr p3 = &n;        // 参照先の値がconst

    p3 = &n;
    *p3 = 1;                // p3 はここでエラー
}