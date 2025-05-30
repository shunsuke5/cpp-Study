#include "ValueFactory.hpp"

Value* ValueFactory::New(int n) const {
    return new Value(n);
}