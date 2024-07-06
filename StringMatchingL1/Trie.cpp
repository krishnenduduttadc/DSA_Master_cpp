#include <iostream>
#include <cstring> // For memset
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        memset(children, 0, sizeof(children));
        isEndOfWord = false;
    }
};

TrieNode* root;

void insertTrie(string s) {
    TrieNode* current = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool searchTrie(string s) {
    TrieNode* current = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current != nullptr && current->isEndOfWord;
}

int main() {
    root = new TrieNode();

    // Hardcoded input strings
    string inputs[] = {"apple", "banana", "orange", "grape"};

    // Insert each input string into the Trie
    for (const string& s : inputs) {
        insertTrie(s);
    }

    // Search for specific strings
    string search1 = "banana";
    string search2 = "mango";

    if (searchTrie(search1)) {
        cout << search1 << " Found" << endl;
    } else {
        cout << search1 << " Not Found" << endl;
    }

    if (searchTrie(search2)) {
        cout << search2 << " Found" << endl;
    } else {
        cout << search2 << " Not Found" << endl;
    }

    return 0;
}
