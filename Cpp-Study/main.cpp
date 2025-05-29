#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

int main() {
    int n[100];
    cout << ARRAY_SIZE(n) << endl;

    IntArray array(5);
    array.Get(6);
}