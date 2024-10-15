#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Length of the array
        cin >> N;

        vector < int > A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i]; // Input the array elements
        }

        sort(A.begin(), A.end());
        vector<int> unique_elements;
         if (N > 0) {
            unique_elements.push_back(A[0]);
        }
        for (int i = 1; i < N; i++) {
           if(A[i]!=A[i-1]){
               unique_elements.push_back(A[i]);
           }
        }
        
        // Output the size of unique elements
        cout << unique_elements.size() << endl;
        
        // Output the unique elements
        for (const int &num : unique_elements) {
            cout << num << " ";
        }
        cout << endl;
        

    }

}


/*
3
2
5 10
4
1 5 5 10
5
4 4 6 6 8

*/