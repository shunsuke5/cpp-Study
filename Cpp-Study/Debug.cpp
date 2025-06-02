#include "Debug.hpp"
#ifdef NDEBUG

#else
#include <iostream>
#include <cstdlib>
using namespace std;

namespace Debug
{
    void Assert(bool b, const char* file, int line)
    {
        if (b) {
            // この条件は常に真でなくてはならない
        } else {
            // しかし、バグのためにそうならなかった場合は
            // ファイル名と行番号を出力して強制終了する
            cerr << file << '(' << line << ')'
                << ": Assertion Error!" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

#endif  // #ifdef NDEBUG