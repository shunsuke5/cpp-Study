#include "Assoc.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

typedef Assoc<int, string> AssocIS;

bool Input(int& n)
{
    cout << "値を入力してください > " << flush;
    n = 0;
    cin >> n;
    return n > 0;
}

void Check(const AssocIS& assoc, int n)
{
    try {
        cout << assoc[n] << endl;
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
}

typedef Assoc<string, string> Setting;

bool Input(string& key)
{
    cout << "文字列を入力してください > " << flush;
    key = "";
    getline(cin, key);
    return !key.empty();
}

void Check(const Setting& setting, const string& key)
{
    try {
        cout << setting[key] << endl;
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }
}

int main()
{
    AssocIS assoc;

    assoc[42] = "Hoge";
    assoc[25] = "Foo";
    assoc[89] = "Bar";
    assoc[11] = "Baz";

    int n;
    while (Input(n)) {
        Check(assoc, n);
    }

    for (int i = 0; i < 500; ++i) {
        std::cin.clear();
    }

    Setting setting;

    setting["Type"] = "Rectangle";
    setting["Size"] = "1024x768";
    setting["Color"] = "Green";

    string key;
    while (Input(key)) {
        Check(setting, key);
    }
}