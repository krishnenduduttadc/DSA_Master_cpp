#include <iostream>
#include <string>
using namespace std;

bool checkDivisibilityBy3(string str) {
    int odd = 0;
    int even = 0;

    for(int i = 0; i < str.length(); i++) {
        int bit = str[i] - '0';

        if(i % 2 == 0) {
            even = even + bit;
        } else {
            odd = odd + bit;
        }
    }

    int d = even - odd;

    return (d % 11 == 0);
}

int main() {
    string str = "333";

    if(checkDivisibilityBy3(str)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
