#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<bool>>& chess) {
    for (int i = 0; i < chess.size(); i++) {
        for (int j = 0; j < chess.size(); j++) {
            if (chess[i][j]) {
                cout << "q\t";
            } else {
                cout << "-\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void queensCombinations(int qpsf, int tq, vector<vector<bool>>& chess, int lcno) {
    if (qpsf == tq) {
        display(chess);
        return;
    }

    for (int cell = lcno + 1; cell < chess.size() * chess.size(); cell++) {
        int row = cell / chess.size();
        int col = cell % chess.size();
        chess[row][col] = true;
        queensCombinations(qpsf + 1, tq, chess, cell);
        chess[row][col] = false;
    }
}

int main() {
    int n = 2;
    vector<vector<bool>> chess(n, vector<bool>(n, false));

    queensCombinations(0, n, chess, -1);

    return 0;
}
