#include <iostream>
#include <string>

using namespace std;

void sol(string q, string a) {
    if (q.length() == 0) {
        cout << a << "-" << endl;
        return;
    }

    char ch = q[0];
    string rest = q.substr(1);
    sol(rest, a);
    sol(rest, a + ch);
}

int main() {
    string s = "abc";
    sol(s, "");

    return 0;
}
