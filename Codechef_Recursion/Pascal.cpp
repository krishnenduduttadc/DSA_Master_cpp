#include <iostream>
using namespace std;

// Recursive function to find the value at Nth row and Mth column
int findPascalsValue(int N, int M) {
    // Base cases
    if (M == 0 || M == N) {
        return 1;
    }
    if(M > N){
        cerr << "Error: Invalid Input" << endl;
        exit(1);
    }
    // Recursive step: value is the sum of the values above it
    return findPascalsValue(N - 1, M - 1) + findPascalsValue(N - 1, M);
}

int main() {
    int N, M;
 
    cin >> N >> M;
  
    
    int result = findPascalsValue(N, M);
    cout << result << endl;

    return 0;
}



/*

4 2
*/