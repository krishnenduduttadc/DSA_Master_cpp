#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> rank_map;

string find(string x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x;
        rank_map[x] = 1;
    }
    
    if (x == parent[x]) {
        return x;
    }
    
    string temp = find(parent[x]);
    parent[x] = temp;
    return temp;
}

void unionSets(string x, string y) {
    string lx = find(x);
    string ly = find(y);
    
    if (lx != ly) {
        if (rank_map[lx] > rank_map[ly]) {
            parent[ly] = lx;
        } else if (rank_map[lx] < rank_map[ly]) {
            parent[lx] = ly;
        } else {
            parent[lx] = ly;
            rank_map[ly]++;
        }
    }
}

bool areSentencesSimilarTwo(vector<string>& Sentence1, vector<string>& Sentence2, vector<vector<string>>& pairs) {
    if (Sentence1.size() != Sentence2.size()) {
        return false;
    }

    for (auto& p : pairs) {
        unionSets(p[0], p[1]);
    }

    for (int i = 0; i < Sentence1.size(); i++) {
        string w1 = Sentence1[i];
        string w2 = Sentence2[i];

        if (w1 != w2 && find(w1) != find(w2)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 3;
    vector<string> sentence1 = {"treat", "fight", "miss"};
    vector<string> sentence2 = {"like", "train", "lost"};
    vector<vector<string>> pairs = {
        {"treat", "catch"},
        {"train", "fight"},
        {"like", "catch"},
        {"miss", "lost"}
    };

    cout << (areSentencesSimilarTwo(sentence1, sentence2, pairs) ? "true" : "false") << endl;

    return 0;
}
