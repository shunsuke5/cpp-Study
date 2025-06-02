#include "Debug.hpp"
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
#include <cstdarg>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

int Sum(int first, ...)
{
    int sum = 0;

    va_list args;
    va_start(args, first);

    for (int n = first; n != 0; n = va_arg(args, int)) {
        sum += n;
    }

    va_end(args);
    return sum;
}

void PrintF(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main()
{
    cout << Sum(0) << ' '
        << Sum(1, 0) << ' '
        << Sum(7, 3, 0) << ' '
        << Sum(1, 2, 3, 4, 5, 0) << endl;

    PrintF("%d%s", 100, "hoge");
}