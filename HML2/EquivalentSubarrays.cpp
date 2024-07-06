#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int ans = 0;
    vector<int> arr = {2, 1, 3, 2, 3};
    unordered_set<int> set;

    // Insert unique elements into the set
    for (int i = 0; i < arr.size(); i++) {
        set.insert(arr[i]);
    }

    int k = set.size();
    int i = -1;
    int j = -1;
    unordered_map<int, int> map;

    while (true) {
        bool f1 = false;
        bool f2 = false;

        // Expand the window until all unique elements are covered
        while (i < arr.size() - 1) {
            f1 = true;
            i++;
            map[arr[i]] = map[arr[i]] + 1; // Add current element to the map
            if (map.size() == k) { // If all unique elements are covered
                ans += arr.size() - i; // Add the number of valid subarrays ending at index i
                break;
            }
        }

        // Slide the window to the right until the uniqueness condition is violated
        while (j < i) {
            f2 = true;
            j++;
            if (map[arr[j]] == 1) {
                map.erase(arr[j]); // Remove element from map if its count is reduced to 0
            } else {
                map[arr[j]] = map[arr[j]] - 1; // Decrease the count of the element
            }

            // If the map size matches k, add the number of valid subarrays again
            if (map.size() == k) {
                ans += arr.size() - i;
            } else {
                break;
            }
        }

        // If both windows cannot be expanded or contracted further, break the loop
        if (!f1 && !f2) {
            break;
        }
    }

    // Print the total number of equivalent subarrays
    cout << ans << endl;

    return 0;
}
