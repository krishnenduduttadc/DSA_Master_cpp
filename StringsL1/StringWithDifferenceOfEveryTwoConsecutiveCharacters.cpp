#include <iostream>
#include <string>
using namespace std;

string solution(string str) {
    if (str.empty()) return "";

    string result;
    result += str[0]; // Append the first character directly
    for (int i = 1; i < str.length(); i++) {
        char curr = str[i];
        char prev = str[i - 1];
        int gap = curr - prev;

        result += to_string(gap); // Append the difference as a string
        result += curr; // Append the current character
    }

    return result;
}

int main() {
    string str = "pepCODinG";
    cout << solution(str) << endl;
    return 0;
}
