#ifndef STACK_H_
#define STACK_H_

#include <stdexcept>

template <typename TYPE>
class Stack
{
public:
    explicit Stack(size_t sizeMax) : m_sizeMax(sizeMax), m_size(0)
    {
        m_array = new TYPE[sizeMax];
    }

    virtual ~Stack() { delete[] m_array; }

public:
    void Push(const TYPE& value)
    {
        CheckOverflow();
        m_array[m_size] = value;
        ++m_size;
    }

    void Pop()
    {
        CheckUnderflow();
        --m_size;
    }

private:
    const TYPE& Top_() const
    {
        CheckUnderflow();
        return m_array[m_size - 1];
    }

public:
    TYPE& Top() { return const_cast<TYPE&>(Top_()); }
    const TYPE& Top() const { return Top_(); }
    bool Full() const { return m_size == m_sizeMax; }
    bool Empty() const { return m_size == 0; }

private:
    void CheckOverflow() const
    {
        if (Full()) {
            throw std::overflow_error("スタックオーバーフロー");
        }
    }

    void CheckUnderflow() const
    {
        if (Empty()) {
            throw std::underflow_error("スタックが空です");
        }
    }

private:
    TYPE* m_array;
    size_t m_sizeMax;
    size_t m_size;
};

#endif // !STACK_H_
