#include "ArrayStream.hpp"

ArrayStream::ArrayStream(const double* array) {
    m_array = array;
    m_i = 0;
}

void ArrayStream::SetBase() {
    m_n = m_array[m_i];
    ++m_i;
}