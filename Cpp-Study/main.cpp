#include "ValueFactory.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#include <typeinfo>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

/*
* クラステンプレートを引数にとるクラステンプレート
*/
template <
    template <typename TYPE, typename ALLOC = allocator<TYPE>> class TEMPL
>
class Hoge {
public:
    void Run() {
        m_v.push_back(1);
        m_v.push_back(3);
        m_v.push_back(5);

        for (size_t i = 0, size = m_v.size(); i < size; ++i) {
            cout << m_v[i] << ' ';
        }
        cout << endl;
    }

private:
    TEMPL<int, allocator<int> > m_v;
};

/*
* 静的な整数定数を引数にとるクラステンプレート
*/
template <int N>
class SBit {
public:
    static const int VALUE = 1 << N;
};

constexpr int add(int a, int b) {
    return a + b;
}

#define BIT(x) (1 << (int) (x))

int main() {
    Hoge<vector> hoge;
    hoge.Run();

    cout << SBit<0>::VALUE << ' '
        << SBit<1>::VALUE << ' '
        << SBit<2>::VALUE << ' '
        << SBit<3>::VALUE << endl;

    /*
    * SBit<int N>は静的な整数定数でのみ初期化されているため、
    * 配列のサイズ指定に使用することが可能
    */
    int array[SBit<8>::VALUE];
    cout << ARRAY_SIZE(array) << endl;  // 256

    /*
    * constexprを使用しても同様のことが可能
    */
    int array1[add(1, 2)];
    cout << ARRAY_SIZE(array1) << endl; // 3

    /*
    * マクロを使用しても同様のことが可能
    */
    int array2[BIT(5)];
    cout << ARRAY_SIZE(array2) << endl; // 32
}