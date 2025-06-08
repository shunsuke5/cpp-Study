#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

unsigned int Factional(unsigned int num)
{
    return num == 0 ? 1 : num * Factional(num - 1);
}

int main()
{
    for (int i = 0; i < 9; ++i) {
        cout << i << "! = " << Factional(i) << endl;
    }
}