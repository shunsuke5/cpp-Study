#include "Debug.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#include <typeinfo>
#include <climits>
#include <cassert>
#include <stdexcept>
#include <cstdarg>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

/*
* 4バイト境界にアラインするため、
* name[21]の後ろに3バイト、sexの後ろに2バイトのパディングが入る
*/
struct Person
{
    char name[21];
    int age;
    char birthmonth;
    char sex;
};

/*
* #pragma pack(最大値) とすることで、
* 揃えるバイト境界のサイズの最大値を設定する
*/
#pragma pack(1)
struct Other
{
    char name[21];
    int age;
    char birthmonth;
    char sex;
};
#pragma pack()

int main(int argc, char* argv[])
{
    cout << "name : " << offsetof(Person, name) << endl             // 0
        << "age : " << offsetof(Person, age) << endl                // 24
        << "birthmonth : " << offsetof(Person, birthmonth) << endl  // 28
        << "sex : " << offsetof(Person, sex) << endl                // 29
        << "size : " << sizeof(Person) << endl;                     // 32

    cout << endl;
        
    cout << "name : " << offsetof(Other, name) << endl              // 0
        << "age : " << offsetof(Other, age) << endl                 // 21
        << "birthmonth : " << offsetof(Other, birthmonth) << endl   // 25
        << "sex : " << offsetof(Other, sex) << endl                 // 26
        << "size : " << sizeof(Other) << endl;                      // 27
}