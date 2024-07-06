#include <iostream>
#include <vector>
using namespace std;

bool IsQueenSafe(vector<vector<bool>>& chess, int row, int col) {
    // Check vertically upwards
    for (int i = row; i >= 0; i--) {
        if (chess[i][col]) {
            return false;
        }
    }

    // Check horizontally left
    for (int j = col; j >= 0; j--) {
        if (chess[row][j]) {
            return false;
        }
    }

    // Check diagonally left upwards
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j]) {
            return false;
        }
    }

    // Check diagonally right upwards
    for (int i = row, j = col; i >= 0 && j < chess.size(); i--, j++) {
        if (chess[i][j]) {
            return false;
        }
    }

    return true;
}

void nqueens(int qpsf, int tq, vector<vector<bool>>& chess, int lcno) {
    if (qpsf == tq) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess.size(); col++) {
                cout << (chess[row][col] ? "Q\t" : "-\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    int n = chess.size();
    for (int i = lcno + 1; i < n * n; i++) {
        int row = i / n;
        int col = i % n;

        if (!chess[row][col] && IsQueenSafe(chess, row, col)) {
            chess[row][col] = true;
            nqueens(qpsf + 1, tq, chess, row * n + col);
            chess[row][col] = false;
        }
    }
}

int main() {
    int n = 4;
    vector<vector<bool>> chess(n, vector<bool>(n, false));

    nqueens(0, n, chess, -1);

    return 0;
}
