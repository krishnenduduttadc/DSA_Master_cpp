#include <bits/stdc++.h>

using namespace std;

void permutation(int cb, int nboxes, vector < int > arr, vector < bool > used, vector<int>& current, set<vector<int>>& allPermutations) {
    if (cb == nboxes) {
        allPermutations.insert(current);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            
            if(i>0 && arr[i]==arr[i-1] && !used[i-1]){
                continue;
            }
            used[i] = true;
            current.push_back(arr[i]);
            permutation(cb + 1, nboxes, arr, used, current,allPermutations);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T; // Read number of test cases
    while (T--) {
        int N;
        cin >> N; // Read the length of the array
        vector < int > A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i]; // Read each element of the array
        }
        sort(A.begin(), A.end());
        int nboxes = N;

        vector < bool > used(N, false);
        vector < int > current;
        set < vector < int >> allPermutations;
        permutation(0, N, A, used, current, allPermutations);
        
        // Print the number of unique permutations
        cout << allPermutations.size() << endl;
        
        for (const auto& permutation : allPermutations) {
            for (int num : permutation) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

}