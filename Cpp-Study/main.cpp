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

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

/*
* 関数ポインタ
*/
int (* const ADD) (int a, int b) = { Add };

/*
* 関数ポインタの配列
*/
int (* const FP_OPERATOR[]) (int a, int b) = {
    Add, Sub, Mul, Div
};

const char* const OPERATION_NAME[] = {
    "加算", "減算", "乗算", "除算" 
};

class Calculator {
public:
    void Run();

private:
    bool Input();
    void Calculate();

private:
    int m_a, m_b;
};

void Calculator::Run() {
    while (Input()) {
        Calculate();
    }
}

bool Calculator::Input() {
    cout << "2つの値を入力してください > " << flush;
    m_b = 0;
    cin >> m_a >> m_b;
    return m_b != 0;
}

void Calculator::Calculate() {
    static const size_t SIZE = ARRAY_SIZE(FP_OPERATOR);
    assert(SIZE == ARRAY_SIZE(OPERATION_NAME));

    for (size_t i = 0; i < SIZE; ++i) {
        int result = FP_OPERATOR[i](m_a, m_b);
        cout << OPERATION_NAME[i] << ": " << result << endl;
    }
}

int main()
{
    cout << ADD(1, 2) << endl;

    Calculator calc;
    calc.Run();
}