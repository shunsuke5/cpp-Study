#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

int main()
{
    /*
    * スタック
    */
    Stack<int> stack(10);

    try {
        for (int i = 0; i < 20; ++i) {
            stack.Push(i);
        }
    } catch (const overflow_error& e) {
        cerr << e.what() << endl;
    }

    while (!stack.Empty()) {
        cout << stack.Top() << ' ';
        stack.Pop();
    }
    cout << endl;

    try {
        stack.Pop();
    } catch (const underflow_error& e) {
        cerr << e.what() << endl;
    }

    cout << endl;

    /*
    * キュー
    */
    Queue<int> queue(10);

    try {
        for (int i = 0; i < 5; ++i) { queue.Push(i); }
        for (int i = 0; i < 3; ++i) { queue.Pop(); }
        for (int i = 0; i < 20; ++i) { queue.Push(i); }
    } catch (const overflow_error& e) {
        cerr << e.what() << endl;
    }

    while (!queue.Empty()) {
        cout << queue.Front() << ' ';
        queue.Pop();
    }
    cout << endl;
}