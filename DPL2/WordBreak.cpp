#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool solution(string sentence, unordered_set<string>& dict) {
    int n = sentence.length();
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            string word = sentence.substr(j, i - j + 1);
            if (dict.find(word) != dict.end()) {
                if (j > 0) {
                    dp[i] += dp[j - 1];
                } else {
                    dp[i] += 1;
                }
            }
        }
    }

    cout << dp[n - 1] << endl;
    return dp[n - 1] > 0;
}

int main() {
    unordered_set<string> dict = {"i", "like", "pep", "coding", "pepper", "eating", "mango", "man", "go", "in", "pepcoding"};
    string sentence = "ilikepeppereatingmangoinpepcoding";

    cout << boolalpha << solution(sentence, dict) << endl;

    return 0;
}
