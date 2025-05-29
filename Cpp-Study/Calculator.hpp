#ifndef CALCULATOR_H_
#define CALCULATOR_H_

class Calculator {
public:
    typedef double ValueType;
public:
    void Run();

private:
    bool Input();
    bool Calculate();
    void ShowResult() const;

private:
    ValueType m_a, m_b;
    char m_op;
    ValueType m_result;
};

#endif // !CALCULATOR