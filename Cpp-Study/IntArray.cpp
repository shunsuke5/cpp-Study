#include "IntArray.hpp"
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

IntArray::IntArray(int size) {
    m_array = new int[size];
    m_size = size;

    cout << "コンストラクタ" << endl;
}

IntArray::IntArray(const IntArray& other) {
    m_array = new int[other.m_size];
    m_size = other.m_size;

    copy(other.m_array, other.m_array + m_size, m_array);
    cout << "コピーコンストラクタ" << endl;
}

IntArray::~IntArray() {
    delete[] m_array;

    cout << "デストラクタ" << endl;
}

void IntArray::operator=(const IntArray& other) {
    int* array = new int[other.m_size];

    delete[] m_array;
    m_array = array;
    m_size = other.m_size;
    copy(other.m_array, other.m_array + m_size, m_array);
}

int IntArray::Get(int i) const {
    CheckIndex(i);
    return m_array[i];
}

void IntArray::Set(int i, int value) {
    CheckIndex(i);
    m_array[i] = value;
}

int IntArray::Size() const {
    return m_size;
}

int& IntArray::operator[](int i) {
    CheckIndex(i);
    return m_array[i];
}

const int& IntArray::operator[](int i) const {
    CheckIndex(i);
    return m_array[i];
}

void IntArray::CheckIndex(int i) const {
    if (i < 0 || i >= m_size) {
        cout << "不正なインデックス" << endl;
        exit(EXIT_FAILURE);
    }
}