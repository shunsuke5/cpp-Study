#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>

template <typename TYPE>
class Queue
{
public:
    explicit Queue(size_t sizeMax) : m_sizeMax(sizeMax), m_size(0), m_begin(0)
    {
        m_array = new TYPE[m_sizeMax];
    }

    virtual ~Queue() { delete[] m_array; }

public:
    void Push(const TYPE& value)
    {
        CheckOverflow();
        m_array[AddIndex(m_begin, m_size)] = value;
        ++m_size;
    }

    void Pop()
    {
        CheckUnderflow();
        m_begin = AddIndex(m_begin, 1);
        --m_size;
    }

private:
    const TYPE& Front_() const
    {
        CheckUnderflow();
        return m_array[m_begin];
    }

public:
    TYPE& Front() { return const_cast<TYPE&>(Front_()); }
    const TYPE& Front() const { return const_cast<TYPE&>(Front_()); }
    bool Full() const { return m_size == m_sizeMax; }
    bool Empty() const { return m_size == 0; }

private:
    size_t AddIndex(size_t i, size_t add) { return (i + add) % m_sizeMax; }

private:
    void CheckOverflow() const
    {
        if (Full()) {
            throw std::overflow_error("キューオーバーフロー");
        }
    }

    void CheckUnderflow() const
    {
        if (Empty()) {
            throw std::underflow_error("キューが空です");
        }
    }

private:
    TYPE* m_array;
    size_t m_sizeMax;
    size_t m_size;
    size_t m_begin;
};

#endif // !QUEUE_H_
