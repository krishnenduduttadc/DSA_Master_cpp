#include <iostream>
using namespace std;

void combinations(int cb, int nboxes, int ssf, int ritems, string asf) {
    if (cb > nboxes) {
        if (ssf == ritems) {
            cout << asf << endl;
        }
        return;
    }
    combinations(cb + 1, nboxes, ssf + 1, ritems, asf + "i");
    combinations(cb + 1, nboxes, ssf, ritems, asf + "-");
}

int main() {
    int nboxes = 3;
    int ritems = 2;
    combinations(1, nboxes, 0, ritems, "");
    return 0;
}
