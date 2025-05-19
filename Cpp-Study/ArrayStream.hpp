#pragma once
#include "Stream.hpp"

class ArrayStream : public Stream {
public:
    ArrayStream(const double* array);
    bool Set();

private:
    const double* m_array;
    int m_i;
};