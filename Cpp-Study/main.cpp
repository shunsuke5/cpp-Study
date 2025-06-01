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

class Calculator
{
public:
    void Run();

private:
    bool Input();
    void Calculate();

private:
    int Add() { return m_a + m_b; }
    int Sub() { return m_a - m_b; }
    int Mul() { return m_a * m_b; }
    int Div() { return m_a / m_b; }

    typedef int (Calculator::*FpOp2) ();
    static const FpOp2 FP_OPERATOR[];

    static const char* const OPERATION_NAME[];

private:
    int m_a, m_b;
};

const Calculator::FpOp2 Calculator::FP_OPERATOR[] =
{
    &Calculator::Add, &Calculator::Sub,
    &Calculator::Mul, &Calculator::Div
};

const char* const Calculator::OPERATION_NAME[] =
{
    "加算", "減算", "乗算", "除算"
};

void Calculator::Run()
{
    while (Input()) {
        Calculate();
    }
}

bool Calculator::Input()
{
    cout << "2つの値を入力してください > " << flush;
    m_b = 0;
    cin >> m_a >> m_b;
    return m_b != 0;
}

void Calculator::Calculate()
{
    static const size_t SIZE = ARRAY_SIZE(FP_OPERATOR);
    assert(SIZE == ARRAY_SIZE(OPERATION_NAME));

    for (size_t i = 0; i < SIZE; ++i) {
        int result = (this->*FP_OPERATOR[i])();
        cout << OPERATION_NAME[i] << ": " << result << endl;
    }
}

int main()
{
    Calculator calc;
    calc.Run();
}