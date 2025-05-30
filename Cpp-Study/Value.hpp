#ifndef VALUE_H_
#define VALUE_H_
#include "ValueFactory.hpp"

class Value {
    friend Value* ValueFactory::New(int n) const;

public:
    int Get() const { return m_n; }

private:
    Value(int n) : m_n(n) {}
    Value(const Value&);
    void operator=(const Value&);
    int m_n;
};

#endif // !VALUE_H_
