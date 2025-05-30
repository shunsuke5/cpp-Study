#include "IntArray.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <chrono>
#include <typeinfo>
using namespace std;

string Hoge(ostream& ostr) {
    ostringstream* sstr = dynamic_cast<ostringstream*>(&ostr);
    if (sstr != NULL) {
        sstr->str("");
        *sstr << "Hoge" << flush;
        return sstr->str();
    } else {
        return "Error";
    }
}

int main() {
    ostringstream sstr;
    cout << Hoge(sstr) << endl;
    cout << Hoge(cout) << endl;

    /*
    * クロスキャスト
    */
    fstream fstr;
    istream& istr = fstr;
    ostream& ostr = dynamic_cast<ostream&>(istr);
}