#include "DList.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

typedef DList<int> List;
typedef List::Node Node;

typedef Node* Node::* ShowDirection;
const ShowDirection SD_FORWARD = &Node::next;
const ShowDirection SD_BACKWARD = &Node::prev;

/*
* ShowDirectionを使用することで正順の走査か逆順の走査かを
* 引数の dir で指定できるようにして、1つの関数にまとめている
*/
void Show(const List& list, ShowDirection dir = SD_FORWARD)
{
    const Node* eol = list.Eol();
    const Node* head = eol->*dir;
    for (const Node* node = head; node != eol; node = node->*dir) {
        cout << node->value << ' ';
    }
    cout << endl;
}

int main()
{
    List list;

    for (int i = 0; i < 5; ++i) {
        list.Push(i);
    }
    Show(list);
    Show(list, SD_BACKWARD);

    for (int i = 5; i < 10; ++i) {
        list.Unshift(i);
    }
    Show(list);

    list.Pop();
    list.Pop();
    list.Shift();
    Show(list);
}