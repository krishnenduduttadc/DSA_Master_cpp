#include <iostream>
#include <queue>
using namespace std;

class LastStoneWeight {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // Push all stones into max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // Smash stones until only one or none remains
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first != second) {
                pq.push(first - second);
            }
        }

        // Return the weight of the last stone or 0 if no stones left
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    // Hardcoded input array of stones
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    // Create an instance of the LastStoneWeight class
    LastStoneWeight solution;

    // Call the lastStoneWeight method and store the result
    int result = solution.lastStoneWeight(stones);

    // Print the result
    cout << "The last stone weight is " << result << endl;

    return 0;
}
