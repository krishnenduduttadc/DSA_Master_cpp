#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class WordLadder {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(startWord) != wordSet.end()) {
            wordSet.erase(startWord);
        }

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord) {
                return steps;
            }

            for (int i = 0; i < word.length(); ++i) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end()) {
                        wordSet.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};

int main() {
    string startWord = "der";
    string targetWord = "dfs";
    vector<string> wordList = {
        "des",
        "der",
        "dfr",
        "dgt",
        "dfs"
    };

    WordLadder obj;
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);

    cout << ans << endl;

    return 0;
}
