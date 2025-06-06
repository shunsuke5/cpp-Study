#include "DList.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

typedef DList<int> List;
typedef List::Node Node;

typedef Node* Node::* ShowDirection;
const ShowDirection SD_FORWARD = &Node::next;
const ShowDirection SD_BACKWARD = &Node::prev;

class Iterator
{
public:
    Iterator(const Node* node) : m_node(node) {}

public:
    int operator*() { return m_node->value; }

    bool operator!=(const Iterator& other) const { return m_node != other.m_node; }

    void operator++() { m_node = m_node->next; }

protected:
    const Node* m_node;
};

/*
* テンプレートにすることで、
* iteratorクラスも配列も渡せるようになる
*/
template <typename ITERATOR>
void Show(ITERATOR begin, ITERATOR end)
{
    for (ITERATOR it = begin; it != end; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main()
{
    List list;

    for (int i = 0; i < 5; ++i) {
        list.Push(i);
    }
    Show(Iterator(list.GetFirst()), Iterator(list.Eol()));

    static const int ARRAY[] = { 1,2,4,8 };
    static const int SIZE = ARRAY_SIZE(ARRAY);
    Show(ARRAY, ARRAY + SIZE);
}