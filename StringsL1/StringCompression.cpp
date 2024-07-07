#include <iostream>
#include <string>
using namespace std;

string compression1(string str) {
    if (str.empty()) return ""; // Handle edge case

    string s;
    s += str[0]; // Append the first character directly
    for (int i = 1; i < str.length(); i++) {
        char curr = str[i];
        char prev = str[i - 1];
        if (curr != prev) {
            s += curr; // Append only if current character is different from previous
        }
    }
    return s;
}

string compression2(string str) {
    if (str.empty()) return ""; // Handle edge case

    string s;
    s += str[0]; // Append the first character directly
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        char curr = str[i];
        char prev = str[i - 1];
        if (curr == prev) {
            count++; // Increment count for consecutive characters
        } else {
            if (count > 1) {
                s += to_string(count); // Append count if it's greater than 1
                count = 1; // Reset count
            }
            s += curr; // Append current character
        }
    }
    if (count > 1) {
        s += to_string(count); // Append the final count if needed
    }
    return s;
}

int main() {
    string str = "wwwwaaadexxxxxx";
    cout << compression1(str) << endl;
    cout << compression2(str) << endl;
    return 0;
}
