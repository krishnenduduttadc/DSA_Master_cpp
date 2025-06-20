#include <iostream>
#include <vector>

using namespace std;

void queensPermutations(int qpsf, int tq, vector<vector<int>>& chess) {
    if (qpsf == tq) {
        for (int i = 0; i < chess.size(); i++) {
            for (int j = 0; j < chess[0].size(); j++) {
                if (chess[i][j] == 0) {
                    cout << "-\t";
                } else {
                    cout << "q" << chess[i][j] << "\t";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < chess.size(); i++) {
        for (int j = 0; j < chess[0].size(); j++) {
            if (chess[i][j] == 0) {
                chess[i][j] = qpsf + 1; // Place queen
                queensPermutations(qpsf + 1, tq, chess);
                chess[i][j] = 0; 
            }
        }
    }
}

int main() {
    int n = 4; 
    vector<vector<int>> chess(n, vector<int>(n, 0)); // Initialize chessboard with zeros
    queensPermutations(0, n, chess); // Start permutation from the first queen (qpsf = 0)
    return 0;
}
