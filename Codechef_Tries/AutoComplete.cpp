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

    bool nodeHasNoChildren(TrieNode* node) {
        for (TrieNode* child : node->children) {
            if (child != nullptr) {
                return false;
            }
        }
        return !node->isEndOfWord;
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

    void autocomplete(string s) {
        TrieNode* current = root;
        for (auto ch : s) {
            int index = ch - 'a';
            if (current->children[index] == NULL) {
                return; // No suggestions if prefix not found
            }
            current = current->children[index];
        }
        string currentWord = s;
        printWordsRecursive(current, currentWord);
    }

    void printWordsRecursive(TrieNode* node, string& currentWord) {
        if (node == NULL) {
            return;
        }

        if (node->isEndOfWord) {
            cout << currentWord << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i] != NULL) {
                currentWord.push_back('a' + i);
                printWordsRecursive(node->children[i], currentWord);
                currentWord.pop_back();
            }
        }
    }
};

int main() {
    Trie trie;

    // Hardcoded number of words
    int n = 10;  
    
    // Hardcoded prefix for autocomplete
    string s = "sa";  
    
    // Hardcoded words to insert into the Trie
    vector<string> words = {
        "hello",
        "world",
        "code",
        "chef",
        "so",
        "safari",
        "safe",
        "safer",
        "save",
        "saved"
    };

    for (const string& word : words) {
        trie.insert(word);
    }

    // Perform autocomplete
    trie.autocomplete(s);

    return 0;
}
