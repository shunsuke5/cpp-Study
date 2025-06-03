#include "SList.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

typedef SList<int> List;
typedef List::Node Node;

void Show(const List& list)
{
    for (const Node* node = list.GetFirst(); node != NULL; node = node->next) {
        cout << node->value << ' ';
    }
    cout << endl;
}

int main()
{
    List list;

    for (int i = 0; i < 10; ++i) {
        list.Unshift(i);
    }
    Show(list);     // 9 8 7 6 5 4 3 2 1 0

    list.Shift();
    Show(list);     // 8 7 6 5 4 3 2 1 0

    list.At(3) = 42;
    Show(list);     // 8 7 6 42 4 3 2 1 0

    list.Clear();
    Show(list);     // (表示なし)
}