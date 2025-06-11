#include "Number.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

union Int
{
    int value;
    unsigned char bytes[sizeof(int)];
};

void Show(const unsigned char* array, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%02X ", array[i]);
    }
    puts("");
}

int main()
{
    Number i = 1;
    Number d = 1.0;
    cout << i << endl;
    cout << d << endl;
    i.PrintSize();  // Valueの宣言がunionなら 8, structなら 16

    Int n;
    n.value = 255;
    Show(n.bytes, ARRAY_SIZE(n.bytes));
}