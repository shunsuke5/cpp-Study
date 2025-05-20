#include "HalfInputStream.hpp"
#include <iostream>
using namespace std;

HalfInputStream::HalfInputStream() : InputStream(-1) {}

void HalfInputStream::SetBase() {
    InputStream::SetBase();
    m_n /= 2;
}