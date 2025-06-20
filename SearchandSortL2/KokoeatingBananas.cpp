#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

bool isPossible(vector<int>& piles, int sp, int h);

int minEatingSpeed(vector<int>& piles, int h) {
    int maxBananas = *max_element(piles.begin(), piles.end());

    if (h == piles.size()) {
        return maxBananas;
    }

    int lo = 1; // Minimum possible speed (1 banana per hour)
    int hi = maxBananas; // Maximum possible speed (max bananas per pile)

    int minSpeed = INT_MAX;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (isPossible(piles, mid, h)) {
            minSpeed = mid; // Update minimum speed found
            hi = mid - 1; // Try for a smaller speed
        } else {
            lo = mid + 1; // Try for a larger speed
        }
    }

    return minSpeed;
}

bool isPossible(vector<int>& piles, int sp, int h) {
    int time = 0;

    for (int bananas : piles) {
        time += ceil(bananas * 1.0 / sp); // ceil(bananas / sp) equivalent
    }

    return time <= h;
}

void printResult(int speed) {
    cout << "Minimum eating speed: " << speed << endl;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int speed = minEatingSpeed(piles, h);

    printResult(speed);

    return 0;
}
