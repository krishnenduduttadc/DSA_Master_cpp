#include <iostream>
#include <vector>
using namespace std;

bool IsKnightSafe(vector<vector<bool>>& chess, int i, int j) {
    // Check all possible knight moves
    if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2])
        return false;
    if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1])
        return false;
    if (i - 2 >= 0 && j + 1 < chess.size() && chess[i - 2][j + 1])
        return false;
    if (i - 1 >= 0 && j + 2 < chess.size() && chess[i - 1][j + 2])
        return false;
    return true;
}

void nknights(int kpsf, int tk, vector<vector<bool>>& chess, int lcno) {
    int n = chess.size();
    if (kpsf == tk) {
        // Print the chessboard configuration
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cout << (chess[row][col] ? "k\t" : "-\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Place knights recursively
    for (int i = lcno + 1; i < n * n; i++) {
        int row = i / n;
        int col = i % n;

        if (!chess[row][col] && IsKnightSafe(chess, row, col)) {
            chess[row][col] = true;
            nknights(kpsf + 1, tk, chess, i);
            chess[row][col] = false;
        }
    }
}

int main() {
    int n = 2;
    vector<vector<bool>> chess(n, vector<bool>(n, false));

    nknights(0, n, chess, -1);

    return 0;
}
