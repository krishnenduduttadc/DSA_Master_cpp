#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Custom comparator for sorting by value/weight ratio in descending order
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}

double fracKnapsack(vector<pair<int, int>>& items, int W) {
    sort(items.begin(), items.end(), cmp);
    double res = 0.0;

    for (const auto& item : items) {
        int wt = item.first;
        int val = item.second;

        if (wt <= W) {
            res += val;
            W -= wt;
        } else {
            res += (val * (double)W) / wt;
            break;
        }
    }

    return res;
}

int main() {
    vector<pair<int, int>> items = {
        {10, 60},
        {40, 40},
        {20, 100},
        {30, 120}
    };
    
    int W = 50;
    cout << fracKnapsack(items, W) << endl;

    return 0;
}
