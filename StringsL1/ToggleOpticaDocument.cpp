#include <iostream>
#include <string>
using namespace std;

string toggleCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            str[i] = 'A' + (ch - 'a'); // Convert lowercase to uppercase
        } else if (ch >= 'A' && ch <= 'Z') {
            str[i] = 'a' + (ch - 'A'); // Convert uppercase to lowercase
        }
    }
    return str;
}

int main() {
    string str = "pepCODinG";
    cout << toggleCase(str) << endl;
    return 0;
}
