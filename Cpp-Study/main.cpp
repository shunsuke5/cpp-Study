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

int main()
{
    int n;
    cin >> n;
    return cin.fail() ? EXIT_FAILURE : EXIT_SUCCESS;
}