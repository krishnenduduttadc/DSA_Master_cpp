#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases 

    while (t--) {
        int n, k;
        cin >> n >> k; // Number of pearls, Number of positions to move

        queue<int> necklace; // Use std::queue

        // Enqueue the elements (pearls) into the queue
        for (int i = 0; i < n; i++) {
            int pearl;
            cin >> pearl;
            necklace.push(pearl);
        }

        // Rotate the queue left by k positions
        for (int i = 0; i < k; i++) {
            int removed = necklace.front();
            necklace.pop();
            necklace.push(removed);
        }

        // Print the modified necklace
        while (!necklace.empty()) {
            int pearl = necklace.front();
            necklace.pop();
            cout << pearl << " ";
        }

        cout << "\n"; // Move to the next line for the next test case
    }

    return 0;
}


/*
2
5 3
1 5 3 4 2
6 5
10 1 2 9 8 2
*/