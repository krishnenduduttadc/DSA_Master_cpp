#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    if (houses.empty()) return 0;

    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int radius = 0;
    int i = 0; // index for houses
    int j = 0; // index for heaters

    while (i < houses.size()) {
        if (houses[i] <= heaters[j]) {
            if (j == 0) {
                radius = max(radius, heaters[j] - houses[i]);
                i++;
                continue;
            }
        } else {
            while (j != heaters.size() - 1 && heaters[j] < houses[i]) {
                j++;
            }
            if (j == 0 || heaters[j] < houses[i]) {
                radius = max(radius, houses[i] - heaters[j]);
                i++;
                continue;
            }
        }

        int distance = min(houses[i] - heaters[j - 1], heaters[j] - houses[i]);
        radius = max(radius, distance);
        i++;
    }

    return radius;
}

void solve(vector<int>& houses, vector<int>& heaters) {
    cout << findRadius(houses, heaters) << endl;
}

int main() {
    vector<int> houses = {3, 9, 2, 4, 11};
    vector<int> heaters = {1, 8, 5};

    solve(houses, heaters);

    return 0;
}
