#include "Fraction.hpp"
#include <ostream>
#include <iostream>
using namespace std;

Fraction::Fraction(double numer, double denom) :
    m_numer(numer), m_denom(denom) {
}

Fraction::operator double() const {
    return m_numer / m_denom;
}

Fraction Fraction::operator*(const Fraction& rop) const {
    return Fraction(
        m_numer * rop.m_numer,
        m_denom * rop.m_denom
    );
}

Fraction Fraction::operator*=(const Fraction& rop) {
    m_numer *= rop.m_numer;
    m_denom *= rop.m_denom;
    return *this;
}

Fraction Fraction::operator-() const {
    return Fraction(-m_numer, m_denom);
}

Fraction& Fraction::operator++() {
    m_numer += m_denom;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction ret = *this;
    m_numer += m_denom;
    return ret;
}

double Fraction::GetNumer() const {
    return m_numer;
}

double Fraction::GetDenom() const {
    return m_denom;
}

Fraction operator*(double lop, const Fraction& rop) {
    return Fraction(lop * rop.GetNumer(), rop.GetDenom());
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    return Fraction(
        f1.m_numer * f2.m_numer,
        f1.m_denom * f2.m_denom
    );
}

ostream& operator<<(ostream& ostr, const Fraction& rop) {
    ostr << rop.GetNumer() << " / " << rop.GetDenom();
    return ostr;
}