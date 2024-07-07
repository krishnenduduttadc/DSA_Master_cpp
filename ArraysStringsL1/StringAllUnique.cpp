#include <iostream>
#include <cstring> // For memset
using namespace std;

bool f(const string& str) {
    if (str.length() > 128) {
        return false; // More than 128 characters cannot have all unique characters
    }

    bool set[128] = {false}; // Assuming ASCII character set

    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (set[val]) {
            return false; // Character already encountered
        }
        set[val] = true; // Mark character as encountered
    }

    return true; // All characters are unique
}

int main() {
    string str = "abcdd";
    cout << boolalpha << f(str) << endl; // Output: false

    return 0;
}
