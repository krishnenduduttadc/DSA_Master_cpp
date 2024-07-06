#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(string s1, string s2) {
    unordered_map<char, int> map;
    
    // Count frequencies of characters in s1
    for (char ch : s1) {
        map[ch]++;
    }

    // Check characters in s2 against the frequency map
    for (char ch : s2) {
        if (map.find(ch) == map.end()) {
            return false; // Character not found in s1
        } else if (map[ch] == 1) {
            map.erase(ch); // Remove entry if frequency becomes zero
        } else {
            map[ch]--; // Decrement the count of the character
        }
    }

    // If map is empty, all characters from s1 and s2 match in frequency
    return map.empty();
}

int main() {
    string s1 = "pepcoding";
    string s2 = "codingpep";
    cout << boolalpha << solution(s1, s2) << endl; // Output: true

    return 0;
}
