#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
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
    
    
};

int main() {
    
    Trie trie;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string word;
        cin>>word;
        trie.insert(word);
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        string word;
        cin>>word;
        if(trie.search(word))
        {
            cout<<"correct"<<endl;
        }
        else{
            cout<<"incorrect"<<endl;
        }
    }
    return 0;
}


/*
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
*/