#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

// Comparator for sorting jobs by profit in descending order
bool cmp(const tuple<char, int, int> a, const tuple<char, int, int> b) {
    return get<2>(a) > get<2>(b);  // Compare profits
}

void printJobScheduling(vector<tuple<char, int, int>>& jobs) {
    // Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), cmp);

    // Find maximum deadline to allocate time slots
    int maxDeadline = 0;
    for (const auto job : jobs) {
        maxDeadline = max(maxDeadline, get<1>(job));
    }

    // Create a set of available slots
    set<int> slots;
    for (int i = 0; i < maxDeadline; ++i) {
        slots.insert(i);
    }

    // Schedule jobs
    for (const auto& job : jobs) {
        char id = get<0>(job);
        int deadline = get<1>(job);

        // Find latest available time slot before deadline
        auto it = slots.upper_bound(deadline - 1);
        if (it != slots.begin()) {
            --it;
            cout << id << " ";  // Schedule job
            slots.erase(it);    // Mark slot as used
        }
    }
}

int main() {
    vector<tuple<char, int, int>> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    printJobScheduling(jobs);
    cout << endl;

    return 0;
}
