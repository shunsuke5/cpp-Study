#include "InputStream.hpp"
#include <iostream>
using namespace std;

InputStream::InputStream(double n) : Stream(n) {}

void InputStream::SetBase() {
    cin >> m_n;
}