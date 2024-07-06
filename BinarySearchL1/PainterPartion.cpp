#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function declaration
long long calculate(vector<int>& weights, long long maxCapacity);

// Function to calculate the minimum time required
long long minTime(vector<int>& weights, int days) {
    long long maxWeight = *max_element(weights.begin(), weights.end());
    long long totalWeight = accumulate(weights.begin(), weights.end(), 0LL);
    long long low = maxWeight;
    long long high = totalWeight;
    long long ans = totalWeight;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long requiredDays = calculate(weights, mid);
        if (requiredDays <= days) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Function to calculate the number of days required for given max capacity
long long calculate(vector<int>& weights, long long maxCapacity) {
    long long days = 1;
    long long sum = 0;
    for (int weight : weights) {
        if (sum + weight > maxCapacity) {
            days++;
            sum = 0;
        }
        sum += weight;
    }
    return days;
}

int main() {
    // Hardcoded input for testing
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    // Calculate and print the minimum weight capacity
    long long result = minTime(weights, days);
    cout << "Minimum weight capacity required: " << result << endl;

    return 0;
}
