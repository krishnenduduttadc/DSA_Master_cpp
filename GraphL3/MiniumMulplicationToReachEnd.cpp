#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end)
{
    queue<pair<int, int>> q;
    q.push({start, 0});

    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for (auto it : arr)
        {
            int num = (it * node) % mod;

            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;

                if (num == end)
                    return steps + 1;

                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};

    int ans = minimumMultiplications(arr, start, end);
    cout << ans << endl;

    return 0;
}
