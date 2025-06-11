#include "Number.hpp"
#include <cassert>
using namespace std;

void Number::operator=(int n)
{
    m_value.int_ = n;
    m_type = INT;
}

void Number::operator=(double n)
{
    m_value.double_ = n;
    m_type = DOUBLE;
}

void Number::PrintSize()
{
    cout << sizeof m_value << endl;
}

ostream& operator<<(std::ostream& ostr, const Number& n)
{
    if (n.m_type == Number::INT) {
        return ostr << "INT(" << n.m_value.int_ << ')';
    } else {
        assert(n.m_type == Number::DOUBLE);
        return ostr << "DOUBLE(" << n.m_value.double_ << ')';
    }
}