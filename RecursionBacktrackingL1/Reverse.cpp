#include <iostream>
using namespace std;

void rev(string str, int n) {
    if (n == 0) {
        return;
    } else {
        cout << str[n-1];
        rev(str, n - 1);
    }
}

void rev2(string str) {
    if (str.length() == 0) {
        return;
    } else {
        string ros = str.substr(1);
        rev2(ros);
        cout << str[0];
    }
}

int main() {
    string aa = "binod";
    rev(aa, aa.length());
    cout << "\n------------\n";
    rev2(aa);
    cout << endl;
    return 0;
}
