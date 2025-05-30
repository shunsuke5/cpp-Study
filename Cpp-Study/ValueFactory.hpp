#ifndef VALUEFACTORY_H_
#define VALUEFACTORY_H_

class Value;

class ValueFactory {
public:
    Value* New(int n) const;
};

#include "Value.hpp"

#endif // !VALUEFACTORY_H_
