#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2) {
    int len = s1.length();
    if (len == s2.length() && len > 0) {
        string s1s1 = s1 + s1;
        // Check if s2 is a substring of s1s1
        return s1s1.find(s2) != string::npos;
    }
    return false;
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if (isRotation(s1, s2)) {
        cout << "s2 is a rotation of s1." << endl;
    } else {
        cout << "s2 is not a rotation of s1." << endl;
    }

    return 0;
}
