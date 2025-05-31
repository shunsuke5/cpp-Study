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
#define ARRAY_SIZE(array) (sizeof *ARRAY_SIZE_(&(array)))
using namespace std;

template <typename TYPE>
class Limits
{
public:
    static const TYPE MIN;
    static const TYPE MAX;
};

/*
* クラス宣言で特殊化
*/
template<>
class Limits<unsigned short>
{
public:
    static const unsigned short MIN = 0;
    static const unsigned short MAX = USHRT_MAX;
};

/*
* 実態定義で特殊化
*/
template<> const int Limits<int>::MIN = INT_MIN;
template<> const int Limits<int>::MAX = INT_MAX;

template <typename TYPE>
void ShowMinMax()
{
    cout << "Type: " << typeid(TYPE).name() << endl
        << " Min: " << Limits<TYPE>::MIN << endl
        << " Max: " << Limits<TYPE>::MAX << endl;
}

/*
* 部分特殊化
*/
template <typename TYPE>
class Value
{
public:
    Value(const TYPE& value) : m_value(value) {}
    void Show() { cout << m_value << endl; }

private:
    TYPE m_value;
};

template <typename FIRST, typename SECOND>
class Value<pair<FIRST, SECOND> >
{
public:
    Value(const FIRST& first, const SECOND& second) :
        m_value(first, second) {}

    void Show() {
        cout << "1st: " << m_value.first << endl
            << "2nd: " << m_value.second << endl;
    }

private:
    pair<FIRST, SECOND> m_value;
};

int main()
{
    ShowMinMax<unsigned short>();
    ShowMinMax<int>();

    Value<int> n(42);
    n.Show();
    Value<pair<int, const char*> > p(1, "Hoge");
    p.Show();
}