#pragma once

class IntArray {
public:
    IntArray(int size);
    IntArray(const IntArray& other);
    ~IntArray();
    void operator=(const IntArray& other);

public:
    int Get(int i);
    void Set(int i, int value);
    int Size();

private:
    void CheckIndex(int i);

private:
    int* m_array;
    int m_size;
};