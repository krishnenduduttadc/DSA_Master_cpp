#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    struct TrieNode {
        char data;
        bool isTerminating;
        TrieNode* children[26];

        TrieNode(char data) {
            this->data = data;
            isTerminating = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');
    }

    bool search(string word) {
        return search(root, word);
    }

    void add(string word) {
        add(root, word);
    }

private:
    bool search(TrieNode* root, string word) {
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

    void add(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminating = true;
            return;
        }
        int childIndex = word[0] - 'a';
        if (root->children[childIndex] == nullptr) {
            root->children[childIndex] = new TrieNode(word[0]);
        }
        add(root->children[childIndex], word.substr(1));
    }
};

int main() {
    Trie t;
    t.add("this");
    t.add("news");

    cout << boolalpha; // Print bool values as "true" or "false"
    cout << t.search("news") << endl; // Output: true
    cout << t.search("test") << endl; // Output: false

    return 0;
}
