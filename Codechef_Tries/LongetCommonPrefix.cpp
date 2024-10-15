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
    string lcp() {
        TrieNode* current = root;
        string prefix;
        while (current != NULL && !current->isEndOfWord) {
            int count = 0;
            int nextind = -1;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (current->children[i] != NULL) {
                    count++;
                    nextind = i;
                }
            }
            if (count == 1) {
                prefix.push_back('a' + nextind);
                current = current->children[nextind];
            } else {
                break;
            }
        }
        return prefix;
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
    cout<<trie.lcp()<<endl;
}



/*
4
call
cat
caller
camera

*/