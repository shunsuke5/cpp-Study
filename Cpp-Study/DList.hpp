#ifndef DLIST_H_
#define DLIST_H_

#include <cassert>
#include <cstddef>

template <typename TYPE>
class DList
{
public:
    struct Node
    {
        TYPE value;
        Node* prev;
        Node* next;
    };

public:
    DList() { m_eol.prev = m_eol.next = &m_eol; }
    virtual ~DList() { Clear(); }

    Node* GetFirst() { return m_eol.next; }
    const Node* GetFirst() const { return m_eol.next; }

    Node* GetLast() { return m_eol.prev; }
    const Node* GetLast() const { return m_eol.prev; }

    const Node* Eol() const { return &m_eol; }

    Node* Insert(Node* next, const TYPE& value)
    {
        assert(next != NULL);
        Node* node = new Node();
        Node* prev = next->prev;

        node->value = value;
        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
        return node;
    }

    void Erase(Node* node)
    {
        assert(node != NULL);
        if (node == &m_eol) { return; }

        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
        delete node;
    }

    Node* Unshift(const TYPE& value) { return Insert(m_eol.next, value); }

    void Shift() { Erase(m_eol.next); }

    Node* Push(const TYPE& value) { return Insert(&m_eol, value); }

    void Pop() { Erase(m_eol.prev); }

    void Clear()
    {
        Node* next;
        for (Node* node = m_eol.next; node != &m_eol; node = next) {
            next = node->next;
            delete node;
        }
        m_eol.prev = m_eol.next = &m_eol;
    }

private:
    Node m_eol;
};

#endif // !DLIST_H_
