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

    bool search(const string& word) {
        TrieNode* node = searchNode(word);
        return (node != NULL && node->isEndOfWord);
    }

    TrieNode* searchNode(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == NULL) {
                return NULL; // Character not found in the trie
            }
            current = current->children[index];
        }
        return current;
    }
};

int main() {
    Trie trie;

    // Hardcoded input
    vector<string> words = {"cat", "call", "bat", "god", "apple"}; // Trie words
    int n = words.size(); // Number of words to insert

    // Insert hardcoded words into the Trie
    for (int i = 0; i < n; i++) {
        trie.insert(words[i]);
    }

    // Hardcoded search words
    vector<string> searchWords = {"apple", "wolf", "god", "puppy"};
    int m = searchWords.size(); // Number of words to search

    // Search for hardcoded words in the Trie
    for (int i = 0; i < m; i++) {
        if (trie.search(searchWords[i])) {
            cout << "correct" << endl;
        } else {
            cout << "incorrect" << endl;
        }
    }
    
    return 0;
}

/*
Hardcoded Input:
5
cat
call
bat
god
apple
4
apple
wolf
god
puppy

Expected Output:
correct
incorrect
correct
incorrect
*/
