#include <iostream>
#include <vector>

using namespace std;

void queensCombinations(int qpsf, int tq, vector<vector<bool>>& chess, int i, int j) {
    // Base case: all queens placed
    if (qpsf == tq) {
        // Print the chessboard configuration
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess[row].size(); col++) {
                if (chess[row][col]) {
                    cout << "q\t";
                } else {
                    cout << "-\t";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Try placing queens in subsequent columns of the current row
    for (int col = j + 1; col < chess.size(); col++) {
        chess[i][col] = true;
        queensCombinations(qpsf + 1, tq, chess, i, col);
        chess[i][col] = false;
    }

    // Try placing queens in subsequent rows
    for (int row = i + 1; row < chess.size(); row++) {
        for (int col = 0; col < chess[row].size(); col++) {
            chess[row][col] = true;
            queensCombinations(qpsf + 1, tq, chess, row, col);
            chess[row][col] = false;
        }
    }
}

int main() {
    int n = 2;
    vector<vector<bool>> chess(n, vector<bool>(n, false));
    queensCombinations(0, n, chess, 0, -1);

    return 0;
}
