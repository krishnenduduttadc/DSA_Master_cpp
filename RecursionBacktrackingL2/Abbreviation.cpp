#include <iostream>
#include <string>
using namespace std;

void solution(string str, string asf, int count, int pos) {
    if (pos == str.length()) {
        if (count == 0) {
            cout << asf << endl;
        } else {
            cout << asf << count << endl;
        }
        return;
    }

    if (count > 0) {
        solution(str, asf + to_string(count) + str[pos], 0, pos + 1);
    } else {
        solution(str, asf + str[pos], 0, pos + 1);
    }

    solution(str, asf, count + 1, pos + 1);
}

int main() {
    string str = "pep";
    solution(str, "", 0, 0);
    return 0;
}
