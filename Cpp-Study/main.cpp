#include "Number.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

/*
* 2バイトの変数 word を、1バイト単位でも扱えるような構造体
* この時、特に構造体に型名が無くても困らない
*/
union Word
{
    unsigned short word;

    struct
    {
        unsigned char low;
        unsigned char high;
    } byte;
};

/*
* 無名列挙体、定数を宣言する場合に便利
*/
enum
{
    ONE = 1, TWO, THREE
};

int main()
{
    Word n = { 0x1234 };
    int n1 = 4660;
    printf("上位バイト： %02X\n", n.byte.high);
    printf("下位バイト： %02X\n", n.byte.low);
}