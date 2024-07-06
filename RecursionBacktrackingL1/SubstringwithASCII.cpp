#include <iostream>
using namespace std;

// Function to generate all substrings including characters and ASCII codes
void subseq(string s, string ans) {
    // Base case: if string s is empty, print the current answer
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }

    // Recursive cases:
    char ch = s[0];
    int code = ch;

    // Exclude the first character from s and continue generating substrings
    subseq(s.substr(1), ans);

    // Include the first character as it is and continue generating substrings
    subseq(s.substr(1), ans + ch);

    // Include the ASCII code of the first character and continue generating substrings
    subseq(s.substr(1), ans + to_string(code));
}

int main() {
    // Call the function with the initial string and an empty initial answer
    subseq("AB", "");
    return 0;
}
