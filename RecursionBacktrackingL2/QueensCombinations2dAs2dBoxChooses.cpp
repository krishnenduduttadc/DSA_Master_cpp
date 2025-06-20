#include <iostream>
#include <string>

using namespace std;

void queensCombinations(int qpsf, int tq, int row, int col, string asf) {
    if (row == tq) {
        if (qpsf == tq) {
            cout << asf << endl;
        }
        return;
    }

    int nr = 0, nc = 0;
    string yasf = "", nasf = "";
    
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

    queensCombinations(qpsf + 1, tq, nr, nc, yasf);
    queensCombinations(qpsf + 0, tq, nr, nc, nasf);
}

int main() {
    int n = 2;
    queensCombinations(0, n, 0, 0, "");

    return 0;
}
