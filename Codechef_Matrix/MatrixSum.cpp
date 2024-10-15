#include <iostream>

using namespace std;

int main() {
    int n, m;
    // Write your code hereint n, m;
    cin >> n >> m;
    
    // Calculate the total sum of the matrix elements
    int totalSum = n * m;
    
    // Check if the total sum is even
    if (totalSum % 2 == 0) {
        // If even, print the matrix with all elements set to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << 1 << " ";
            }
            cout << endl;
        }
    } else {
        // If odd, print -1 as it's not possible
        cout << -1 << endl;
    }

    return 0;
}

/*
2 2
*/