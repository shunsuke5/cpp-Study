#ifndef STACK_H_
#define STACK_H_

#include <stdexcept>

template <typename TYPE>
class Stack
{
public:
    /*
    * メモリ領域をchar配列として確保しているだけなので、
    * TYPEのコンストラクタは呼ばれない
    */
    explicit Stack(size_t sizeMax) : m_sizeMax(sizeMax), m_size(0)
    {
        m_array = new char[m_sizeMax * sizeof(TYPE)];
    }

    /*
    * 「char配列として」m_arrayを確保しているため、
    * Clear()を行わないと「char配列として」メモリが解放され、
    * TYPEのデストラクタが呼ばれないことに注意する
    */
    virtual ~Stack()
    {
        Clear();
        delete[] m_array;
    }

public:
    void Push(const TYPE& value)
    {
        CheckOverflow();
        new(&GetAt(m_size)) TYPE(value);    // TYPEのコピーコンストラクタ呼び出し
        ++m_size;
    }

    void Pop()
    {
        CheckUnderflow();
        --m_size;
        GetAt(m_size).~TYPE();              // TYPEのデストラクタ呼び出し
    }

private:
    const TYPE& Top_() const
    {
        CheckUnderflow();
        return GetAt(m_size - 1);
    }

public:
    TYPE& Top() { return const_cast<TYPE&>(Top_()); }
    const TYPE& Top() const { return Top_(); }
    bool Full() const { return m_size == m_sizeMax; }
    bool Empty() const { return m_size == 0; }

    void Clear()
    {
        while (m_size > 0) {
            Pop();
        }
    }

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
    // 配列内の指定された要素への参照を、charからTYPEへ変換して返す
    const TYPE& GetAt_(size_t i) const { return reinterpret_cast<const TYPE&>(m_array[i * sizeof(TYPE)]); }

    TYPE& GetAt(size_t i) { return const_cast<TYPE&>(GetAt_(i)); }
    const TYPE& GetAt(size_t i) const { return GetAt_(i); }

private:
    char* m_array;
    size_t m_sizeMax;
    size_t m_size;
};

#endif // !STACK_H_
