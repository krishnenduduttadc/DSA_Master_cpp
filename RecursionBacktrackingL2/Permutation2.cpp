#include <iostream>
using namespace std;

void permutations(int cb, int nboxes, int items[], int ssf, int ritems, string asf) {
    if (cb > nboxes) {
        if (ssf == ritems) {
            cout << asf << endl;
        }
        return;
    }

    for (int i = 0; i < ritems; i++) {
        if (items[i] == 0) {
            items[i] = 1;
            permutations(cb + 1, nboxes, items, ssf + 1, ritems, asf + to_string(i + 1));
            items[i] = 0;
        }
    }

    permutations(cb + 1, nboxes, items, ssf, ritems, asf + "0");
}

int main() {
    int nboxes = 3;
    int ritems = 2;
    int cb = 1;
    int ssf = 0;
    int items[ritems] = {0}; // Initialize items array with 0s

    permutations(cb, nboxes, items, ssf, ritems, "");

    return 0;
}
