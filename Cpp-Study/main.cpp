#include "Stack.hpp"
#include "Queue.hpp"
#include <iostream>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

class Hoge
{
public:
    explicit Hoge(int n) : m_n(n) {}
    int Get() const { return m_n; }
private:
    int m_n;
};

int main()
{
    /*
    * コピーコンストラクタは明示的に作成しなかった場合、
    * 暗黙に作られるので以下の一文も問題なく動作する
    */
    Stack<Hoge> stack(10);

    try {
        for (int i = 0; i < 20; ++i) {
            stack.Push(Hoge(i));
        }
    } catch (const overflow_error& e) {
        cerr << e.what() << endl;
    }

    while (!stack.Empty()) {
        cout << stack.Top().Get() << ' ' << flush;
        stack.Pop();
    }
    cout << endl;
}