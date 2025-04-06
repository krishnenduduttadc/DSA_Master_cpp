#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int> people, int limit) {
    int boats = 0;
    sort(people.begin(), people.end());

    int left = 0, right = people.size() - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            boats++;
            left++;
            right--;
        } else {
            boats++;
            right--;
        }
    }

    return boats;
}

int main() {
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    int boats = numRescueBoats(people, limit);
    cout << boats << endl; // Output should be 3

    return 0;
}
