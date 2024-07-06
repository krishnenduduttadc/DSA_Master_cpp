#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void solution(string str, string pattern, unordered_map<char, string>& map, string op) {
    // Base case: If pattern is empty
    if (pattern.length() == 0) {
        // If both str and op are empty, print the mapping
        if (str.length() == 0) {
            unordered_set<char> alreadyPrinted;
            for (char ch : op) {
                if (alreadyPrinted.find(ch) == alreadyPrinted.end()) {
                    cout << ch << " -> " << map[ch] << ", ";
                    alreadyPrinted.insert(ch);
                }
            }
            cout << "." << endl;
        }
        return;
    }

    // Recursive case
    char ch = pattern[0];
    string rop = pattern.substr(1);

    if (map.find(ch) != map.end()) {
        // If the character already has a mapping
        string previousMapping = map[ch];
        if (str.length() >= previousMapping.length()) {
            string left = str.substr(0, previousMapping.length());
            string right = str.substr(previousMapping.length());

            if (previousMapping == left) {
                solution(right, rop, map, op);
            }
        }
    } else {
        // If the character doesn't have a mapping, try all possible mappings
        for (int i = 0; i < str.length(); i++) {
            string left = str.substr(0, i + 1);
            string right = str.substr(i + 1);
            map[ch] = left;
            solution(right, rop, map, op);
            map.erase(ch);
        }
    }
}

int main() {
    string str = "graphtreesgraph";
    string pattern = "pep";
    unordered_map<char, string> map;

    solution(str, pattern, map, pattern);

    return 0;
}
