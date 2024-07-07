#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int cap) {
    int l = -1;
    for (auto& trip : trips) {
        l = max(l, trip[1]);
    }

    vector<int> h(l + 1, 0);

    for (auto& trip : trips) {
        h[trip[0]] += trip[2];
        h[trip[1]] -= trip[2];
    }

    for (int i = 1; i <= l; i++) {
        h[i] += h[i - 1];
        if (h[i] > cap) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> trips = {
        {1, 5, 2},
        {4, 8, 1},
        {11, 15, 3}
    };
    int cap = 3;

    if (carPooling(trips, cap)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
