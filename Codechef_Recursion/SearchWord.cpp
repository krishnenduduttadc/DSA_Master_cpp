#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
    if (k == word.size()) return true; // All characters in the word have been found
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
    
    char tmp = board[i][j]; // Temporarily store the current cell
    board[i][j] = '#'; // Mark as visited
    
    // Explore in all four directions
    bool found = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1);
    
    board[i][j] = tmp; // Restore original value
    return found; // Return whether the word was found
}

bool wordSearch(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (dfs(board, word, i, j, 0)) return true; // Start DFS from each cell
        }
    }
    return false; // Word not found
}

int main() {
    // Hardcoded input
    int R = 3; // Number of rows
    int C = 4; // Number of columns
    vector<vector<char>> board = {
        {'a', 'b', 'c', 'e'},
        {'s', 'f', 'c', 's'},
        {'a', 'd', 'e', 'e'}
    };
    string word = "abcced"; // Word to search

    cout << (wordSearch(board, word) ? "true" : "false") << endl; // Output the result
    return 0;
}
