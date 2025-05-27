#ifndef FRACTION_H_
#define FRACTION_H_
#include <ostream>

class Fraction {
public:
    Fraction(double numer = 0, double denom = 1);
    operator double() const;
    Fraction operator*(const Fraction& rop) const;
    Fraction operator*=(const Fraction& rop);
    Fraction operator-() const;
    Fraction& operator++();
    Fraction operator++(int);

public:
    double GetNumer() const;
    double GetDenom() const;

private:
    double m_numer;
    double m_denom;

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

Fraction operator*(double lop, const Fraction& rop);

std::ostream& operator<<(std::ostream& ostr, const Fraction& rop);

#endif // !FRACTION_H_