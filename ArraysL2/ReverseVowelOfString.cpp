#include <iostream>
#include <string>
#include <algorithm>

bool isVowel(char ch) {
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

std::string reverseVowel(std::string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && !isVowel(s[left])) {
            left++;
        }

        while (left < right && !isVowel(s[right])) {
            right--;
        }

        if (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {
    std::string s = "hello";
    std::string result = reverseVowel(s);
    std::cout << result << std::endl; // Output should be "holle"
    return 0;
}
