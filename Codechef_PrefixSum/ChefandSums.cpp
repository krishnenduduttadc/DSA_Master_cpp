#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T = 2;
    cout << T << endl;

    int N = 3;
    cout << N << endl;
    cout << "1 2 3" << endl;

    N = 4;
    cout << N << endl;
    cout << "2 1 3 1" << endl;

    int n = 3; 
    vector<int> A = {1, 2, 3};
    
    int minElement = A[0];
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (A[i] < minElement) {
            minElement = A[i];
            minIndex = i;
        }
    }
    
    cout << minIndex + 1 << "\n";

    n = 4; 
    A = {2, 1, 3, 1};

    minElement = A[0];
    minIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (A[i] < minElement) {
            minElement = A[i];
            minIndex = i;
        }
    }
    
    cout << minIndex + 1 << "\n";

    return 0;
}
