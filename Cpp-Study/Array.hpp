#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

template <typename TYPE>
class Array {
public:
    Array(int size);
    Array(const Array& other);
    void operator=(const Array& other);
    virtual ~Array();
    void Error();

public:
    TYPE Get(int i) const;
    void Set(int i, TYPE value);

public:
    int Size() const;

private:
    void CheckIndex(int i) const;

private:
    TYPE* m_array;
    const int m_size;
};

/*
* 実装部分
*/

template <typename TYPE>
Array<TYPE>::Array(int size) : m_size(size) {
    m_array = new TYPE[size];
}

template <typename TYPE>
Array<TYPE>::Array(const Array& other) : m_size(other.m_size) {
    m_array = new TYPE[m_size];
    std::copy(other.m_array, other.m_array + m_size, m_array);
}

template <typename TYPE>
void Array<TYPE>::operator=(const Array& other) {
    if (m_size != other.m_size) {
        throw std::length_error("長さが違います");
    }

    std::copy(other.m_array, other.m_array + m_size, m_array);
}

template <typename TYPE>
Array<TYPE>::~Array() {
    delete[] m_array;
}

template <typename TYPE>
void Array<TYPE>::Error() {
    m_size = 0;
}

template <typename TYPE>
TYPE Array<TYPE>::Get(int i) const {
    CheckIndex(i);
    return m_array[i];
}

template <typename TYPE>
void Array<TYPE>::Set(int i, TYPE value) {
    CheckIndex(i);
    m_array[i] = value;
}

template <typename TYPE>
int Array<TYPE>::Size() const {
    return m_size;
}

template <typename TYPE>
void Array<TYPE>::CheckIndex(int i) const {
    if (i < 0 || i > m_size) {
        std::cerr << "インデックスが不正です" << std::endl
            << "値 : " << i << std::endl;
        std::exit(EXIT_FAILURE);
    }
}