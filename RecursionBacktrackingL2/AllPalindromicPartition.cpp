#include <iostream>
#include <string>
using namespace std;

void sol(string str, string asf);
bool isPalin(string s);

void runMain() {
    string str = "abba";
    sol(str, "");
}

void sol(string str, string asf) {
    if (str.length() == 0) {
        cout << asf << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        string prefix = str.substr(0, i + 1);
        string ros = str.substr(i + 1);
        if (isPalin(prefix)) {
            sol(ros, asf + "(" + prefix + ")");
        }
    }
}

bool isPalin(string s) {
    int li = 0;
    int ri = s.length() - 1;
    while (li < ri) {
        if (s[li] != s[ri]) {
            return false;
        }
        li++;
        ri--;
    }
    return true;
}

int main() {
    runMain();
    return 0;
}
