#include <iostream>
using namespace std;

void combination(int cb, int tb, int ssf, int ts, string asf) {
    if (cb > tb) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    combination(cb + 1, tb, ssf + 1, ts, asf + "i");
    combination(cb + 1, tb, ssf, ts, asf + "-");
}

int main() {
    int nboxes = 4;
    int ritems = 2;
    combination(1, nboxes, 0, ritems, "");
    return 0;
}
