#include <iostream>
#include <queue>
using namespace std;

void lastStoneAndWinner(int n, vector<int>& stones) {
    queue<int> q;
    for (int stone : stones) q.push(stone);
    
    int player = 0;  // 1 for Akshar, 0 for Aman
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
    cout << player << " " << q.front() << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> stones(N);
        for (int i = 0; i < N; i++) {
            cin >> stones[i];
        }
        lastStoneAndWinner(N, stones);
    }
    return 0;
}

/*

3
3
-5 0 5
4 
-1 -3 2 4
6
-100000 0 0 100000 -1000000 1000000

*/