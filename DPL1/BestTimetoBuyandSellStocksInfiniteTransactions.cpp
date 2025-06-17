#include <iostream>
#include <vector>

using namespace std;

// Function to calculate max profit with multiple transactions allowed
int maxProfit(vector<int> prices) {
    if (prices.empty()) return 0;

    int buyDay = 0;
    int sellDay = 0;
    int profit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] >= prices[i - 1]) {
            sellDay++;
        } else {
            profit += prices[sellDay] - prices[buyDay];
            buyDay = sellDay = i;
        }
    }

    profit += prices[sellDay] - prices[buyDay];
    return profit;
}

int main() {
    // Test case
    vector<int> prices = {11, 6, 7, 19, 4, 1, 6, 18, 4};
    int result = maxProfit(prices);
    cout << "Max profit: " << result << endl; // Output: 30

    return 0;
}
