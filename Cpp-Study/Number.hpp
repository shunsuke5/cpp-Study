#ifndef NUMBER_H_
#define NUMBER_H_

#include <iostream>

class Number
{
private:
    enum Type { INT, DOUBLE };

public:
    Number(int n = 0) { operator=(n); }
    Number(double n) { operator=(n); }
    void operator=(int n);
    void operator=(double n);
    void PrintSize();

public:
    friend std::ostream& operator<<(std::ostream& ostr, const Number& n);

private:
    union Value
    {
        int int_;
        double double_;
    };

    Value m_value;
    Type m_type;
};

#endif // !NUMBER_H_
