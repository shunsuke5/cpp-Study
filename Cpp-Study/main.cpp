#include "Integer.hpp"
#include "a.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    Integer a(100), b(300);
    a.Show();   // 300
    b.Show();   // 300

    A aaa(500);
    aaa.Show(); // 500
    a.Show();   // 500

    A bbb(700);
    bbb.Show(); // 700
    aaa.Show(); // 700
    a.Show();   // 700

    aaa.Print();    // 10 10
    bbb.Print();    // 10 10
}