#include "ValueFactory.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#include <typeinfo>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

namespace Hoge {
    using namespace std;

    void Hello() {
        cout << "やあ、こんちは。" << endl;
    }
}

class Show {
public:
    static void Value(char ch) { cout << ch << endl; }
    static void Value(const char* str) { cout << str << endl; }
};

class Show2 : public Show {
public:
    static void Value(char ch) {
        int n = static_cast<unsigned char>(ch);
        cout << n << endl;
    }

    using Show::Value;
};

int main() {
    Hoge::cout << "やあ、こんちは。" << Hoge::endl;
    Hoge::Hello();

    Show2::Value('A');
    Show2::Value("Hoge");
}