#include "Integer.hpp"

class A : public Integer {
public:
    A(int num = 0);
    void Print();

public:
    static const int ARRAY_SIZE = 10;

private:
    // 静的メンバ定数はメンバ変数である配列のサイズに指定可能
    int m_array[ARRAY_SIZE];
};