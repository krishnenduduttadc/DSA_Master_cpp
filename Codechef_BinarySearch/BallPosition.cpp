#include <bits/stdc++.h>
using namespace std;

bool canPlaceBalls(vector<int>& positions, int k, long long minDist) {
    int count = 1;
    int lastPos = positions[0];
    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPos >= minDist) {
            ++count;
            lastPos = positions[i];
            if (count == k) return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    long long left = 0, right = positions[n-1] - positions[0], result = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canPlaceBalls(positions, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << '\n';
    return 0;
}


/*
6 4
1 2 4 8 9 12


*/