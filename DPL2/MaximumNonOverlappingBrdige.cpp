#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Bridge {
    int north;
    int south;

    Bridge(int n, int s) : north(n), south(s) {}

    bool operator<(const Bridge& other) const {
        if (north != other.north) {
            return north < other.north;
        } else {
            return south < other.south;
        }
    }
};

int MaximumNonOverlappingBridges(int n, vector<int>& nr, vector<int>& s) {
    vector<Bridge> bdgs;
    vector<int> dp(n, 1);
    int omax = 1;

    // Initialize bridges array
    for (int i = 0; i < n; i++) {
        bdgs.push_back(Bridge(nr[i], s[i]));
    }

    // Sort bridges based on north coordinates (and south in case of ties)
    sort(bdgs.begin(), bdgs.end());

    // Calculate LIS using dynamic programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (bdgs[j].south <= bdgs[i].south) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        omax = max(omax, dp[i]);
    }

    return omax;
}

int main() {
    int n = 10;
    vector<int> nr = {10, 2, 8, 17, 21, 50, 41, 60, 80, 1};
    vector<int> s = {20, 7, 15, 3, 40, 4, 57, 80, 90, 30};

    int maxNonOverlappingBridges = MaximumNonOverlappingBridges(n, nr, s);
    cout << maxNonOverlappingBridges << endl;

    return 0;
}
