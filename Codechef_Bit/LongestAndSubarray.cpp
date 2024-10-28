#include <bits/stdc++.h>
using namespace std;

int main() {


    int T = 5;
    vector<int> test_cases = {1, 2, 3, 4, 7};

    for (int i = 0; i < T; ++i) {
        int N = test_cases[i];
        
        int power = 1;
        while ((power << 1) <= N) {
            power <<= 1;
        }
        
        int length1 = N - power + 1;
        int length2 = power / 2;
        
        cout << max(length1, length2) << "\n";
    }

    return 0;
}
