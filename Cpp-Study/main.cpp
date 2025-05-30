#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

class IObject {
public:
    virtual ~IObject() {}
    virtual string GetString() const = 0;
};

class IInt : virtual public IObject {
public:
    virtual int GetInt() const = 0;
};

class IDouble : virtual public IObject {
public:
    virtual double GetDouble() const = 0;
};

class Double : virtual public IInt, virtual public IDouble {
public:
    Double(double x) : m_x(x) {}

public:
    virtual string GetString() const {
        ostringstream ostr;
        ostr << "Double(" << m_x << ')';
        return ostr.str();
    }

    int GetInt() const {
        return static_cast<int>(m_x);
    }

    double GetDouble() const {
        return m_x;
    }

private:
    const double m_x;
};

ostream& operator<<(ostream& ostr, const IObject& obj) {
    return ostr << obj.GetString();
}

void ShowInt(const IInt& obj) {
    cout << "int: " << obj.GetInt() << endl;
}

void ShowDouble(const IDouble& obj) {
    cout << "double: " << obj.GetDouble() << endl;
}

int main() {
    Double n = 1.2;
    IInt& i = n;
    IDouble& d = n;
    IObject& o = n;

    cout << n << endl;
    ShowInt(n);
    ShowDouble(n);
    
    cout << i << endl;
    ShowInt(i);
    
    cout << d << endl;
    ShowDouble(d);
    
    cout << o << endl;
}