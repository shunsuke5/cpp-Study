#include <iostream>
#include <cstdlib>
using namespace std;

#define WINDOWS
#ifdef WINDOWS
#define CURRENT
#else
#define CURRENT "./"
#endif // WINDOWS

const char FILENAME[] = CURRENT "main.cpp";

int main()
{
    if (system(FILENAME) == 0) {
        cout << "プログラムは正常に実行されました" << endl;
        return EXIT_SUCCESS;
    } else {
        cerr << "実行に失敗しました" << endl;
        return EXIT_FAILURE;
    }
}