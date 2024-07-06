#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char getHighestFrequencyChar(string str) {
    unordered_map<char, int> hm; // HashMap to store character frequencies

    // Count frequencies of characters in the string
    for (char ch : str) {
        hm[ch]++;
    }

    char mfc = str[0]; // Initialize most frequent character with the first character

    // Find the character with the highest frequency
    for (auto it = hm.begin(); it != hm.end(); ++it) {
        if (it->second > hm[mfc]) {
            mfc = it->first;
        }
    }

    return mfc;
}

int main() {
    string str = "zmszeqxllzvheqwrofgcuntypejcxovtaqbnqyqlmrwitc";

    char highestFreqChar = getHighestFrequencyChar(str);

    cout << highestFreqChar << endl;

    return 0;
}
