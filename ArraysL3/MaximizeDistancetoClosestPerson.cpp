#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MaximizeDistancetoClosestPerson {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dist = INT_MIN;
        int i = -1;

        for (int j = 0; j < seats.size(); j++) {
            if (seats[j] == 1) {
                if (i == -1) {
                    dist = max(dist, j);
                } else {
                    dist = max(dist, (j - i) / 2);
                }
                i = j;
            }
        }

        dist = max(dist, static_cast<int>(seats.size()) - 1 - i);

        return dist;
    }
};

int main() {
    MaximizeDistancetoClosestPerson solution;

    // Test case 1
    vector<int> seats1 = {1, 0, 0, 0, 1, 0, 1};
    int result1 = solution.maxDistToClosest(seats1);
    cout << "Max distance to closest person: " << result1 << endl; // Expected output: 2

    return 0;
}
