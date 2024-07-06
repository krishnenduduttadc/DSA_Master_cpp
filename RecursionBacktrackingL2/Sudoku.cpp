#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<int>>& board, int x, int y, int val) {
    // Check row and column
    for (int j = 0; j < board[0].size(); j++) {
        if (board[x][j] == val) {
            return false;
        }
    }
    for (int i = 0; i < board.size(); i++) {
        if (board[i][y] == val) {
            return false;
        }
    }
    
    // Check 3x3 sub-grid
    int smi = (x / 3) * 3;
    int smj = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[smi + i][smj + j] == val) {
                return false;
            }
        }
    }
    
    return true;
}

void solveSudoku(vector<vector<int>>& board, int i, int j) {
    if (i == board.size()) {
        display(board);
        return;
    }
    
    int ni = 0, nj = 0;
    if (j == board[0].size() - 1) {
        ni = i + 1;
        nj = 0;
    } else {
        ni = i;
        nj = j + 1;
    }
    
    if (board[i][j] != 0) {
        solveSudoku(board, ni, nj);
    } else {
        for (int po = 1; po <= 9; po++) {
            if (isValid(board, i, j, po)) {
                board[i][j] = po;
                solveSudoku(board, ni, nj);
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(arr, 0, 0);

    return 0;
}
