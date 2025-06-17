#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum profit
int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int maxProfit = 0;
    int minBuyPrice = prices[0];

    for (int price : prices) {
        int todayProfit = price - minBuyPrice;
        maxProfit = max(maxProfit, todayProfit);
        minBuyPrice = min(minBuyPrice, price);
    }

    return maxProfit;
}

int main() {
    // Test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);

    cout << "Max profit: " << result << endl; // Output: 5

    return 0;
}
