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

class ABase {
public:
    ABase(int x) : m_x(x) {}
    virtual ~ABase() {}

public:
    void Show() {
        cout << m_x << endl;
    }

private:
    int m_x;
};

class A1 : virtual public ABase {
public:
    A1() : ABase(1) {}
};

class A2 : virtual public ABase {
public:
    A2() : ABase(2) {}
};

class C : public A1, public A2 {
public:
    C() : ABase(3) {}
};

int main() {
    A1 a1;
    A2 a2;
    C c;

    a1.Show();  // 1
    a2.Show();  // 2
    c.Show();   // 3
}