#include "DumpFile.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    DumpFile d;

    if (d.Run()) {
        return EXIT_FAILURE;
    }
}