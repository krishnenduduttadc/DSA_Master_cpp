#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    char data;
    bool isTerminating;
    TrieNode* children[26];
};

TrieNode* createNode(char data) {
    TrieNode* node = new TrieNode;
    node->data = data;
    node->isTerminating = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = nullptr;
    }
    return node;
}

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
    TrieNode* root = createNode('\0');
    add(root, "this");
    add(root, "news");
    cout << boolalpha;
    cout << search(root, "news") << endl; // Output: true
    cout << search(root, "test") << endl; // Output: false

    return 0;
}
