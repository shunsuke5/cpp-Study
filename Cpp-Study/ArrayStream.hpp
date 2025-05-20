#pragma once
#include "Stream.hpp"

class ArrayStream : public Stream {
public:
    ArrayStream(const double* array, int size);
    ~ArrayStream();

protected:
    void SetBase();

private:
    double* m_array;
    int m_i;
};