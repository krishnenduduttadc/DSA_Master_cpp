#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class PathwithMaxEffort {
public:
    struct Tuple {
        int distance;
        int row;
        int col;

        Tuple(int distance, int row, int col) : distance(distance), row(row), col(col) {}
    };

    int MinimumEffort(vector<vector<int>>& heights) {
        // Lambda function to define the comparator for priority_queue
        auto cmp = [](const Tuple& a, const Tuple& b) {
            return a.distance > b.distance; // Min-heap based on distance
        };

        // Priority queue with custom comparator
        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push(Tuple(0, 0, 0));

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        while (!pq.empty()) {
            Tuple it = pq.top();
            pq.pop();
            int diff = it.distance;
            int row = it.row;
            int col = it.col;

            if (row == n - 1 && col == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m) {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push(Tuple(newEffort, newr, newc));
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    PathwithMaxEffort obj;
    int ans = obj.MinimumEffort(heights);

    cout << ans << endl;

    return 0;
}
