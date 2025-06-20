#include <iostream>
#include <vector>

using namespace std;

void printKnightsTour(vector<vector<int>>& chess, int r, int c, int move);
void displayBoard(vector<vector<int>>& chess);

int main() {
    int n = 5; // Size of the chessboard
    int r = 0; // Starting row
    int c = 0; // Starting column

    vector<vector<int>> chess(n, vector<int>(n, 0));
    printKnightsTour(chess, r, c, 1);

    return 0;
}

void printKnightsTour(vector<vector<int>>& chess, int r, int c, int move) {
    int n = chess.size();
    if (r < 0 || c < 0 || r >= n || c >= n || chess[r][c] > 0) {
        return;
    } else if (move == n * n) {
        chess[r][c] = move;
        displayBoard(chess);
        chess[r][c] = 0;
        return;
    }

    chess[r][c] = move;
    printKnightsTour(chess, r - 2, c + 1, move + 1);
    printKnightsTour(chess, r - 1, c + 2, move + 1);
    printKnightsTour(chess, r + 1, c + 2, move + 1);
    printKnightsTour(chess, r + 2, c + 1, move + 1);
    printKnightsTour(chess, r + 2, c - 1, move + 1);
    printKnightsTour(chess, r + 1, c - 2, move + 1);
    printKnightsTour(chess, r - 1, c - 2, move + 1);
    printKnightsTour(chess, r - 2, c - 1, move + 1);
    chess[r][c] = 0;
}

void displayBoard(vector<vector<int>>& chess) {
    int n = chess.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
