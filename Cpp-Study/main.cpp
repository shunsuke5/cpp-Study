#include "Fraction.hpp"
#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

void Show(const IntArray& array) {
    cout << array.Size() << endl;
}

int main() {
    //Show(5);  // explicitによりコンパイルエラー

    Fraction f1(5, 7);
    Fraction f2(3, 4);
    double n = 2;

    cout << f1 << endl;     // 5 / 7

    /* operator-() const */
    cout << -f2 << endl;    // -3 / 4

    /* operator double() const */
    double d = f1;
    cout << d << endl;      // 0.714286

    /* 暗黙のキャスト fd = Fraction(d) */
    Fraction fd = d;
    cout << fd << endl;     // 0.714286/1

    /* メンバ関数の operator*() */
    // 参考書にはメンバ関数、非メンバ関数の両方が定義されている場合
    // メンバ関数の方が優先されると記述があるが、
    // 「演算子 * があいまい」とエラーが出てしまうのはなぜ？
    Fraction f3 = f1 * f2;
    cout << f3 << endl;     // 15 / 28

    /* operator*=() */
    f1 *= f2;
    cout << f1 << endl;     // 15 / 28

    /* operator++(), oprator++(int) */
    cout << ++f3 << endl;   // 43 / 28
    cout << f3++ << endl;   // 43 / 28
    cout << f3 << endl;     // 71 / 28

    Fraction fff(1,1);
    cout << fff << endl;    // 1 / 1

    /* 非メンバ関数の operator*() */
    fff = n * f1;
    cout << fff << endl;    // 30 / 28
}