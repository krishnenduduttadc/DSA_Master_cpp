#include <iostream>
#include <string>
using namespace std;

// Define TrieNode structure
struct TrieNode {
    char data;
    bool isTerminating;
    TrieNode* children[26];
};

// Create a new TrieNode
TrieNode* createNode(char data) {
    TrieNode* node = new TrieNode;
    node->data = data;
    node->isTerminating = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = nullptr;
    }
    return node;
}

// Add a word to the Trie
void add(TrieNode* root, const string& word) {
    if (word.length() == 0) {
        root->isTerminating = true;
        return;
    }

    int childIndex = word[0] - 'a';
    if (root->children[childIndex] == nullptr) {
        root->children[childIndex] = createNode(word[0]);
    }
    add(root->children[childIndex], word.substr(1));
}

// Search for a word in the Trie
bool search(TrieNode* root, const string& word) {
    if (word.length() == 0) {
        return root->isTerminating;
    }

    int childIndex = word[0] - 'a';
    TrieNode* child = root->children[childIndex];
    if (child == nullptr) {
        return false;
    }
    return search(child, word.substr(1));
}

int main() {
    // Initialize the Trie root
    TrieNode* root = createNode('\0');

    // Add words
    add(root, "this");
    add(root, "news");

    // Search words
    cout << boolalpha;
    cout << search(root, "news") << endl; // Output: true
    cout << search(root, "test") << endl; // Output: false

    return 0;
}
