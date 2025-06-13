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

public:
    friend std::ostream& operator<<(std::ostream& ostr, const Number& n);

private:
    /*
    * 共用体タグ、共用体変数どちらも宣言していないため、
    * Numberクラスのメンバ変数であるかのように直接アクセスできる
    * メモリ領域も共有される
    */
    union
    {
        int m_int;
        double m_double;
    };
    Type m_type;
};

#endif // !NUMBER_H_
