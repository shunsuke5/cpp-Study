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
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

void Dump(const void* vp, size_t size)
{
    static const int WIDTH = 16;
    const char* p = static_cast<const char*>(vp);

    for (size_t i = 0; i < size; ++i) {
        if (i % WIDTH == 0 && i != 0) {
            cout << endl;
        }
        printf("%02X ", p[i]);
    }
    cout << endl;
}

int main()
{
    /*
    * voidへのポインタを元の型でキャストして
    * 参照先へとアクセスする
    */
    char c = '1';
    int i = 2;
    double d = 3;
    void* p;

    p = &c;
    cout << *static_cast<char*>(p) << ' ';
    p = &i;
    cout << *static_cast<int*>(p) << ' ';
    p = &d;
    cout << *static_cast<double*>(p) << endl;

    /*
    * 引数にvoidへのポインタを利用して
    * 様々なデータを受け取れるようにする
    */
    int n = 0x12345678;
    const char str[] = "Hello!";

    Dump(&n, sizeof n);
    Dump(str, sizeof str);
}