#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#include <typeinfo>
#include <climits>
#include <cassert>
#include <stdexcept>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

/*
* それぞれのOSごとに違うマクロを定義しておくことで
* その環境における改行コードを表す文字列を定義することができる
*/
#ifdef WINDOWS
const char LF_CODE[] = "\r\n";
#elif defined(MAC)
const char LF_CODE[] = "\r";
#else
const char LF_CODR[] = "\n";
#endif

/*
* どんな環境であっても確実に32ビットの符号なし整数になる型を作る
*/
#define UINT32_MAX 0xFFFFFFFF

#if UINT_MAX == UINT32_MAX
typedef unsigned int UInt32;
#elif ULONG_MAX == UINT32_MAX
typedef unsigned long UInt32
#elif USHRT_MAX == UINT32_MAX
typedef unsigned short UInt32
#elif UCHAR_MAX == UINT32_MAX
typedef unsigned char UInt32
#else
#error 32ビットの符号なし型が存在しません
#endif

/*
* DEBUG ... または DEBUG(...) と記述することで、
* デバッグ時にしか動作しないコードを実現する
*/

// DEBUG ... の形でシンプルだが、リリース時にもif文が残ってしまう
#ifdef NDEBUG
#define DEBUG if(true) {} else
#else
#define DEBUG if(false) {} else
#endif

// DEBUG(...) の形でかっこが付いてしまうが、リリース時には文が完全に消える
#ifdef NDEBUG
#define DEBUG(body)
#else
#define DEBUG(body) body
#endif

double Average(const int* array, size_t size) {
    // リリースモード時は判定処理を行わない
#ifndef NDEBUG
    if (array == NULL) {
        throw invalid_argument("Averageに変な引数が渡されました");
    }
#endif

    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += array[i];
    }
    return static_cast<double>(sum) / size;
}

int main()
{
    int value[] = {
        12,56,23,93,84,45,77,87,100,45
    };

    cout << "平均値 : " << Average(value, ARRAY_SIZE(value)) << endl;

    UInt32 i = 1;
    cout << i << endl;
    cout << typeid(i).name() << endl;

    DEBUG(cout << 'a' << endl);
}