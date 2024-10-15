#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
    if (k == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
    char tmp = board[i][j];
    board[i][j] = '#'; // Mark as visited
    bool found = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) ||
                 dfs(board, word, i, j+1, k+1) || dfs(board, word, i, j-1, k+1);
    board[i][j] = tmp; // Restore original value
    return found;
}

bool wordSearch(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    cout << (wordSearch(board, word) ? "true" : "false") << endl;
    return 0;
}


/*
3 4
a b c e
s f c s
a d e e
abcced

*/