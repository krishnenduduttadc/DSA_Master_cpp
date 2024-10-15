#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countCommonElements(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0, count = 0;
    
    while (i < A.size() && j < B.size()) {
        if (A[i] == B[j]) {
            count++;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    return count;
}

int main() {
    int T, N;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        cin >> N;
        vector<int> A(N), B(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        cout << countCommonElements(A, B) << endl;
    }
    
    return 0;
}

/*
3
4
1 2 3 4
1 3 4 5
3
2 4 1
1 4 2
1
2
3

*/