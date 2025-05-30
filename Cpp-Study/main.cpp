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

void CheckType(const ostream& ostr) {
    const type_info& tiOstr = typeid(ostr);
    const type_info& tiOstream = typeid(ostream);
    const type_info& tiOfstream = typeid(ofstream);
    const type_info& tiCOfstream = typeid(const ofstream);
    const type_info& tiCROfstream = typeid(const ofstream&);

    cout << boolalpha;

    cout << "(==)" << endl
        << "ostream :" << (tiOstr == tiOstream) << endl
        << "ofstream :" << (tiOstr == tiOfstream) << endl
        << "const ofstream :" << (tiOstr == tiCOfstream) << endl
        << "ostream :" << (tiOstr == tiCROfstream) << endl;
    
    cout << "(!=)" << endl
        << "ostream :" << (tiOstr != tiOstream) << endl
        << "ofstream :" << (tiOstr != tiOfstream) << endl
        << "const ofstream :" << (tiOstr != tiCOfstream) << endl
        << "ostream :" << (tiOstr != tiCROfstream) << endl;
}

int main() {
    ofstream ofstr;
    CheckType(ofstr);
}