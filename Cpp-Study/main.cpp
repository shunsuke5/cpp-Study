#include "DumpFile.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    DumpFile dump;

    if (!dump.Run()) {
        return EXIT_FAILURE;
    }
}