#include <iostream>
#include <string>
using namespace std;

bool oneEditAway(const string& f, const string& s);

bool oneEditReplace(const string& s1, const string& s2) {
    bool found = false;
    for (string::size_type i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (found) {
                return false;
            }
            found = true;
        }
    }
    return true;
}

bool oneEditInsert(const string& s1, const string& s2) {
    string::size_type index1 = 0;
    string::size_type index2 = 0;

    while (index2 < s2.length() && index1 < s1.length()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(const string& f, const string& s) {
    if (f.length() == s.length()) {
        return oneEditReplace(f, s);
    } else if (f.length() + 1 == s.length()) {
        return oneEditInsert(f, s);
    } else if (f.length() - 1 == s.length()) {
        return oneEditInsert(s, f);  // Swap f and s for insertion case
    }
    return false;
}

int main() {
    cout << boolalpha;  // Print bools as true/false instead of 1/0

    cout << oneEditAway("pale", "ple") << endl;  // true
    cout << oneEditAway("pale", "bae") << endl;  // false

    return 0;
}
