#include <iostream>
using namespace std;

int main() {
    int t = 2;
    long long test_cases[2][2] = {
        {10, 10},
        {30, 7}
    };

    for (int i = 0; i < t; i++) {
        long long n = test_cases[i][0];
        long long k = test_cases[i][1];
        
        long long sum = 1;
        
        for (long long j = 1; j < k; j++) {
            sum = sum * ((n - k) + j) / j;
        }
        cout << sum << endl;
    }
    return 0;
}
