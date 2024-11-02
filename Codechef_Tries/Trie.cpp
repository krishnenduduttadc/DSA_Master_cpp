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
    
    void deleteWord(const string& word) {
        deleteWordRecursive(root, word, 0);
    }
    
    bool deleteWordRecursive(TrieNode* node, const string& word, int depth) {
        if (node == nullptr) {
            return false;
        }

        if (depth == word.length()) {
            if (!node->isEndOfWord) {
                return false; // Word not present in the trie
            }

            node->isEndOfWord = false;

            // If the node has no children, it can be safely removed
            return nodeHasNoChildren(node);
        }

        int index = word[depth] - 'a';
        if (deleteWordRecursive(node->children[index], word, depth + 1)) {
            // Delete the child node if it can be deleted
            delete node->children[index];
            node->children[index] = nullptr;

            // Check if the current node has no children and is not an end-of-word node
            return nodeHasNoChildren(node);
        }

        return false;
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
    
    void printAllWords() {
        string currentWord;
        printWordsRecursive(root, currentWord);
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

    // Hardcoded commands and words
    vector<pair<string, string>> commands = {
        {"insert", "cat"},
        {"insert", "cats"},
        {"insert", "dog"},
        {"insert", "hello"},
        {"words", ""},
        {"search", "hello"},
        {"delete", "hello"},
        {"search", "hello"}
    };

    // Execute hardcoded commands
    for (const auto& command : commands) {
        if (command.first == "insert") {
            trie.insert(command.second);
        } else if (command.first == "words") {
            trie.printAllWords();
        } else if (command.first == "search") {
            if (trie.search(command.second)) {
                cout << "present" << endl;
            } else {
                cout << "not present" << endl;
            }
        } else if (command.first == "delete") {
            trie.deleteWord(command.second);
        }
    }
    
    return 0;
}

/*
Hardcoded Input Explanation:
- Insert the words: "cat", "cats", "dog", "hello"
- Print all words
- Search for "hello"
- Delete "hello"
- Search for "hello" again

Expected Output:
cat
cats
dog
hello
present
not present
*/
