#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void lastStoneAndWinner(int n, vector<int>& stones) {
    queue<int> q;
    for (int stone : stones) q.push(stone);
    
    int player = 0;  // 1 for Akshat, 0 for Aman
    while (q.size() > 1) {
        // Aman's turn
        if (player == 0) {
            q.push(q.front()); q.pop(); // Move 1
            q.pop();                     // Move 2
        }
        // Akshat's turn
        else {
            q.push(q.front()); q.pop(); // Move 1
            q.push(q.front()); q.pop(); // Move 1
            q.pop();                     // Move 2
        }
        player = 1 - player; // Switch player
    }
    cout << player << " " << q.front() << endl; // Output player and last stone
}

int main() {
    // Hardcoded input for testing
    int T = 3;
    vector<vector<int>> testCases = {
        {-5, 0, 5},
        {-1, -3, 2, 4},
        {-100000, 0, 0, 100000, -1000000, 1000000}
    };

    for (int i = 0; i < T; i++) {
        vector<int> stones = testCases[i];
        lastStoneAndWinner(stones.size(), stones);
    }

    return 0;
}

/*
Test cases:
3
3
-5 0 5
4 
-1 -3 2 4
6
-100000 0 0 100000 -1000000 1000000
*/
