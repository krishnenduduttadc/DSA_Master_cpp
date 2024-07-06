#include <iostream>
#include <vector>

using namespace std;

void queensPermutations(int qpsf, int tq, int row, int col, string asf, vector<bool>& queens) {
    // Base case: all queens placed
    if (row == tq) {
        if (qpsf == tq) {
            cout << asf << endl << endl;
        }
        return;
    }

    int nr = 0, nc = 0;
    string sep = " ";
    if (col == tq - 1) {
        nr = row + 1;
        nc = 0;
        sep = "\n";
    } else {
        nr = row;
        nc = col + 1;
        sep = "\t";
    }

    // Try placing queens in each column for the current row
    for (int i = 0; i < tq; i++) {
        if (!queens[i]) {
            queens[i] = true;
            queensPermutations(qpsf + 1, tq, nr, nc, asf + "q" + to_string(i + 1) + sep, queens);
            queens[i] = false;
        }
    }

    // Place no queen in this position
    queensPermutations(qpsf, tq, nr, nc, asf + "-" + sep, queens);
}

int main() {
    int n = 2;
    vector<bool> queens(n, false); // Initialize all queens as not placed
    queensPermutations(0, n, 0, 0, "", queens);

    return 0;
}
