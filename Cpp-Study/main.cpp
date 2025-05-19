#include "InputStream.hpp"
#include "ArrayStream.hpp"
#include <iostream>
using namespace std;

int main() {
    InputStream stream;
    cout << "> " << flush;
    stream.Set();

    const Stream& ref = stream;
    cout << ref.Get() << endl;
}