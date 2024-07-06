#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

void wordBreak(string str, string ans, unordered_set<string>& dict) {
    if (str.length() == 0) {
        cout << ans << endl;
        return;
    }
    
    for (int i = 0; i < str.length(); i++) {
        string left = str.substr(0, i + 1);
        if (dict.find(left) != dict.end()) {
            string right = str.substr(i + 1);
            wordBreak(right, ans + left + " ", dict);
        }
    }
}

int main() {
    int n = 5;
    unordered_set<string> dict = {"microsoft", "hiring", "at", "kolkata"};
    string sentence = "microsofthiring";

    wordBreak(sentence, "", dict);

    return 0;
}
