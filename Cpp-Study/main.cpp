#include <iostream>
#include <string>
#define ARRAY_SIZE(array) (sizeof (array) / sizeof *(array))
using namespace std;

bool Match(const char* str, const char* pat)
{
    for (; !(*str == '\0' || *pat == '\0'); ++str, ++pat) {
        if (*pat == '*') {
            for (++pat; ; ++str) {
                if (Match(str, pat)) {
                    return true;
                }

                if (*str == '\0') {
                    return false;
                }
            }
        } else {
            if (*pat != *str) {
                return false;
            }
        }
    }

    return *pat == *str;
}

bool Input(string& str)
{
    cout << "> " << flush;
    getline(cin, str);
    return !(cin.fail() || str == "");
}

int main()
{
    string str, pat;
    while (Input(str) && Input(pat)) {
        cout << (Match(str.c_str(), pat.c_str()) ? "マッチ" : "NOマッチ") << endl;
    }
}