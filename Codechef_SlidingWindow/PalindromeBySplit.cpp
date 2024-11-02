#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> test_cases = {
        {4, 3, 7, 6, 4},
        {5, 1, 4, 5, 4, 1},
        {5, 1, 2, 3, 4, 5}
    };

    for (const auto& test_case : test_cases) {
        int n = test_case[0];
        deque<int> dq(test_case.begin() + 1, test_case.end());

        int ans = 0;
        while (dq.size() > 1) {
            int x = dq.front(), y = dq.back();
            dq.pop_front(); dq.pop_back();
            if (x == y) continue;
            ++ans;
            if (x < y) dq.push_back(y - x);
            else dq.push_front(x - y);
        }
        cout << ans << '\n';
    }

    return 0;
}
