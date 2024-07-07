#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

// Function prototype
bool isPossible(vector<int>& piles, int sp, int h);

// Function to find the minimum eating speed
int minEatingSpeed(vector<int>& piles, int h) {
    // Find the maximum number of bananas in a single pile
    int maxBananas = *max_element(piles.begin(), piles.end());

    // If h equals the number of piles, return the max bananas per pile
    if (h == piles.size()) {
        return maxBananas;
    }

    // Binary search for the minimum eating speed
    int lo = 1; // Minimum possible speed (1 banana per hour)
    int hi = maxBananas; // Maximum possible speed (max bananas per pile)

    int minSpeed = INT_MAX;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Check if it's possible to eat all bananas within h hours at speed mid
        if (isPossible(piles, mid, h)) {
            minSpeed = mid; // Update minimum speed found
            hi = mid - 1; // Try for a smaller speed
        } else {
            lo = mid + 1; // Try for a larger speed
        }
    }

    return minSpeed;
}

// Function to check if eating at speed sp is possible within h hours
bool isPossible(vector<int>& piles, int sp, int h) {
    int time = 0;

    // Calculate total time required to eat all bananas at speed sp
    for (int bananas : piles) {
        time += ceil(bananas * 1.0 / sp); // ceil(bananas / sp) equivalent
    }

    return time <= h;
}

// Utility function to test and print the result
void printResult(int speed) {
    cout << "Minimum eating speed: " << speed << endl;
}

int main() {
    // Hardcoded input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    // Call the minEatingSpeed function to find the result
    int speed = minEatingSpeed(piles, h);

    // Print the result
    printResult(speed);

    return 0;
}
