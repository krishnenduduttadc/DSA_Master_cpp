#include<bits/stdc++.h>
using namespace std;

int countWays(int S) {
    if (S < 0) return 0;
    if (S == 0) return 1;
    return countWays(S - 1) + countWays(S - 2);
}

int main() {
    int S;
    cin >> S;
    cout << countWays(S) << endl;
    return 0;
}


/*
3

*/