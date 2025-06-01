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
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

struct Point
{
    int x, y;
};

inline void IncPointMem(Point* pt, int size, int Point::* mp)
{
    for (int i = 0; i < size; ++i) {
        ++(pt[i].*mp);
    }
}

void IncX(Point* pt, int size)
{
    IncPointMem(pt, size, &Point::x);
}

void IncY(Point* pt, int size)
{
    IncPointMem(pt, size, &Point::y);
}

void Show(const Point* pt, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << pt[i].x << ", " << pt[i].y << endl;
    }
}

int main()
{
    Point pt[] = {
        {0,0}, {1,1}, {2,2}, {3,3}
    };
    int size = ARRAY_SIZE(pt);

    IncX(pt, size);
    IncY(pt, size);
    IncY(pt, size);
    Show(pt, size);
}