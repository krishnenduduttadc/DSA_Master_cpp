#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Hardcoded number of test cases
    int t = 2; // Number of test cases

    // Test Case 1
    cout << "Test Case 1:" << endl;
    int n1 = 5; // Number of pearls
    int k1 = 3; // Number of positions to move
    int pearls1[] = {1, 5, 3, 4, 2}; // Pearls

    queue<int> necklace1; // Use std::queue for Test Case 1
    for (int i = 0; i < n1; i++) {
        necklace1.push(pearls1[i]);
    }

    // Rotate the queue left by k positions
    for (int i = 0; i < k1; i++) {
        int removed = necklace1.front();
        necklace1.pop();
        necklace1.push(removed);
    }

    // Print the modified necklace for Test Case 1
    while (!necklace1.empty()) {
        int pearl = necklace1.front();
        necklace1.pop();
        cout << pearl << " ";
    }
    cout << "\n"; // Move to the next line for the next test case

    // Test Case 2
    cout << "Test Case 2:" << endl;
    int n2 = 6; // Number of pearls
    int k2 = 5; // Number of positions to move
    int pearls2[] = {10, 1, 2, 9, 8, 2}; // Pearls

    queue<int> necklace2; // Use std::queue for Test Case 2
    for (int i = 0; i < n2; i++) {
        necklace2.push(pearls2[i]);
    }

    // Rotate the queue left by k positions
    for (int i = 0; i < k2; i++) {
        int removed = necklace2.front();
        necklace2.pop();
        necklace2.push(removed);
    }

    // Print the modified necklace for Test Case 2
    while (!necklace2.empty()) {
        int pearl = necklace2.front();
        necklace2.pop();
        cout << pearl << " ";
    }
    cout << "\n"; // Move to the next line for the next test case

    return 0;
}

/*
Hardcoded Input:
2
5 3
1 5 3 4 2
6 5
10 1 2 9 8 2

Expected Output:
3 4 2 1 5 
2 10 1 2 9 8 
*/
