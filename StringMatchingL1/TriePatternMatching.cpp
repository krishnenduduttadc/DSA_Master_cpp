#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Node {
    Node* nxt[ALPHABET_SIZE];
    bool is_end;

    Node() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            nxt[i] = nullptr;
        }
        is_end = false;
    }
};

Node* root;

void insert_trie(string s) {
    Node* cur = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (cur->nxt[index] == nullptr) {
            cur->nxt[index] = new Node();
        }
        cur = cur->nxt[index];
    }
    cur->is_end = true;
}

bool search_trie(string s) {
    Node* cur = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (cur->nxt[index] == nullptr) {
            return false;
        }
        cur = cur->nxt[index];
    }
    return cur->is_end;
}

int main() {
    root = new Node();

    string text = "ababba";
    string pat = "aba";

    // Insert the pattern into the Trie
    insert_trie(pat);

    // Check if the pattern exists in the text
    if (search_trie(pat)) {
        cout << "Pattern '" << pat << "' found in text." << endl;
    } else {
        cout << "Pattern '" << pat << "' not found in text." << endl;
    }

    return 0;
}
