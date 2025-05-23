#include "Array.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    const char* error = NULL;
    ifstream file;
    string line;

    file.open("test.txt");
    if (!file.is_open()) {
        error = "ファイルを開けませんでした";
        goto ON_ERROR;
    }

    getline(file, line);
    if (file.fail()) {
        cerr << "ファイルを読み込めませんでした" << endl;
        return EXIT_FAILURE;
    }

    cout << line << endl;

ON_ERROR:
    if (error != NULL) {
        cerr << error << endl;
        return EXIT_FAILURE;
    }
}