#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        memset(children, 0, sizeof(children)); // Initialize children to NULL
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == NULL) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    string lcp() {
        TrieNode* current = root;
        string prefix;
        while (current != NULL && !current->isEndOfWord) {
            int count = 0;
            int nextIndex = -1;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (current->children[i] != NULL) {
                    count++;
                    nextIndex = i;
                }
            }
            if (count == 1) {
                prefix.push_back('a' + nextIndex);
                current = current->children[nextIndex];
            } else {
                break;
            }
        }
        return prefix;
    }
};

int main() {
    Trie trie;

    // Hardcoded input
    vector<string> words = {"call", "cat", "caller", "camera"};
    int n = words.size(); // Number of hardcoded words

    for (int i = 0; i < n; i++) {
        trie.insert(words[i]);
    }
    cout << trie.lcp() << endl; // Output the longest common prefix
}

/*
Hardcoded Input:
4
call
cat
caller
camera

Expected Output:
ca
*/
