#include "a.hpp"
#include <iostream>
using namespace std;

A::A(int num) : Integer(num) {}

void A::Print() {
    cout << ARRAY_SIZE << ' ' << flush;
    cout << sizeof m_array / sizeof m_array[0] << endl;
}