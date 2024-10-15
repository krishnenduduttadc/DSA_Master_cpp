#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read the size of the array
        vector<int> A(N);
        int xorsum = 0;
        
        // Read the array and calculate the XOR of all elements
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            xorsum ^= A[i];
        }
        
        // Determine the result for the current test case
        if (N % 2 == 1 || xorsum == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}


/*
3
4
3 2 2 3
6
0 1 2 3 4 5
3
1 2 4


*/