#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void gen(int i, string ustr, int ssf, int ts, string asf) {
    if (i == ustr.length()) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    char ch = ustr[i];
    gen(i + 1, ustr, ssf + 1, ts, asf + ch);
    gen(i + 1, ustr, ssf, ts, asf);
}

int main() {
    string str = "abcabcdef";
    int k = 3;
    unordered_set<char> unique;
    string ustr = "";

    // Extract unique characters from str
    for (char ch : str) {
        if (unique.find(ch) == unique.end()) {
            unique.insert(ch);
            ustr += ch;
        }
    }

    gen(0, ustr, 0, k, "");

    return 0;
}
