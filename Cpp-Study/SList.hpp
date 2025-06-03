#ifndef SLIST_H_
#define SLIST_H_

#include <cassert>
#include <cstddef>

template <typename TYPE>
class SList
{
public:
    struct Node
    {
        TYPE value;
        Node* next;
    };

public:
    SList() { m_eol.next = NULL; }
    virtual ~SList() { Clear(); }

    Node* GetFirst() { return m_eol.next; }
    const Node* GetFirst() const { return m_eol.next; }

    Node* Insert(Node* node, const TYPE& value)
    {
        assert(node != NULL);
        Node* next = new Node();
        next->value = value;
        next->next = node->next;
        return node->next = next;
    }

    Node* Unshift(const TYPE& value)
    {
        return Insert(&m_eol, value);
    }

    void EraseNextNode(Node* node)
    {
        assert(node != NULL);
        Node* next = node->next;
        assert(next != NULL);
        node->next = next->next;
        delete next;
    }

    void Shift()
    {
        EraseNextNode(&m_eol);
    }

    void Clear()
    {
        Node* next;
        for (Node* node = m_eol.next; node != NULL; node = next) {
            next = node->next;
            delete node;
        }
        m_eol.next = NULL;
    }

private:
    const TYPE& At_(int i) const
    {
        const Node* node = m_eol.next;
        for (int j = 0; j < i; ++j) {
            node = node->next;
        }
        return node->value;
    }

public:
    TYPE& At(int i) { return const_cast<TYPE&>(At_(i)); }
    const TYPE& At(int i) const { return At_(i); }

private:
    Node m_eol;
};

#endif // !SLIST_H_
