#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long long n) {
    if (n < 0) {
        return false; // Negative numbers cannot be perfect squares
    }
    long long res = sqrt(n);
    if (res * res == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N;
    cin >> N; // Read the number of shops
    vector < long long > a(N);
    long long s = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i]; 
        s += a[i];// Read the number of tiles for each shop
    }

    
    
    if (isPerfectSquare(s)) {
        cout << "yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}


/*
3
4 9 7
*/