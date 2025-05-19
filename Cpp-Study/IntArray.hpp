#pragma once

class IntArray {
public:
    IntArray(int size);
    IntArray(const IntArray& other);
    ~IntArray();
    void operator=(const IntArray& other);

public:
    int Get(int i) const;
    void Set(int i, int value);
    int Size() const;

private:
    void CheckIndex(int i) const;

private:
    int* m_array;
    int m_size;
};