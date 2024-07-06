#include <iostream>
#include <string>

using namespace std;

void queensCombinations(int qpsf, int tq, int row, int col, string asf) {
    // Base case: all queens placed
    if (row == tq) {
        if (qpsf == tq) {
            cout << asf << endl;
        }
        return;
    }

    // Variables for next row and column, and strings for queen placed and not placed
    int nr = 0, nc = 0;
    string yasf = "", nasf = "";
    
    // Determine next row and column based on current position
    if (col == tq - 1) {
        nr = row + 1;
        nc = 0;
        yasf = asf + "q\n";
        nasf = asf + "-\n";
    } else {
        nr = row;
        nc = col + 1;
        yasf = asf + "q";
        nasf = asf + "-";
    }

    // Recursive calls for placing or not placing queen in current position
    queensCombinations(qpsf + 1, tq, nr, nc, yasf);
    queensCombinations(qpsf + 0, tq, nr, nc, nasf);
}

int main() {
    int n = 2;
    queensCombinations(0, n, 0, 0, "");

    return 0;
}
