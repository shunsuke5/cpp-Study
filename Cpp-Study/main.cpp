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

bool Input(double& value)
{
    cout << "数値を入力してください > " << flush;
    value = 0;
    cin >> value;
    return value != 0;
}

void Show(string* str)
{
    /*
    * ショートサーキットのおかげで、strがNULLの場合に
    * str->empty()を実行することがなくなり、安全である
    */
    if (!(str == NULL || str->empty())) {
        cout << *str << endl;
    }
}

int main()
{
    double a, b;
    while (Input(a) && Input(b)) {
        cout << "a / b = " << (a / b) << endl
            << "b / a = " << (b / a) << endl;
    }

    Show(NULL);
    string str;
    Show(&str);
    str = "Hoge";
    Show(&str);
}