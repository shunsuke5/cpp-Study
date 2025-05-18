#include "IntArray.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <new>
using namespace std;

void Show(IntArray array) {
	for (int i = 0; i < array.Size(); i++) {
		cout << array.Get(i) << ' ';
	}
	cout << endl;
}

int main() {
	IntArray array0to9(10);
	
	for (int i = 0; i < array0to9.Size(); i++) {
		array0to9.Set(i, i);
	}
	Show(array0to9);

	return 0;
}