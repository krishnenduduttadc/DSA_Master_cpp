#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void gen(string ustr, int cs, int ts, int lc, string asf) {
    if (cs > ts) {
        cout << asf << endl;
        return;
    }
    for (int i = lc + 1; i < ustr.length(); i++) {
        char ch = ustr[i];
        gen(ustr, cs + 1, ts, i, asf + ch);
    }
}

int main() {
    string str = "abcabcd";
    int k = 3;
    unordered_set<char> unique;
    string ustr = "";

    for (char ch : str) {
        if (unique.find(ch) == unique.end()) {
            unique.insert(ch);
            ustr += ch;
        }
    }

    gen(ustr, 1, k, -1, "");

    return 0;
}
