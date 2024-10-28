#include <bits/stdc++.h>
using namespace std;

// Function to calculate lcm of 3 integers
int lcm(int a, int b) {
    return a / __gcd(a, b) * b; // Corrected LCM calculation using GCD
}

int lcm(int a, int b, int c) {
    return lcm(a, lcm(b, c));
}
 
int main() {
    int t = 5; // Number of test cases
    vector<tuple<int, int, int, int>> test_cases = {
        {10, 2, 3, 2},
        {5, 3, 2, 4},
        {6, 3, 3, 3},
        {24, 12, 2, 12},
        {20, 3, 20, 3}
    };

    for (int i = 0; i < t; ++i) {
        int n = get<0>(test_cases[i]);
        int a = get<1>(test_cases[i]);
        int b = get<2>(test_cases[i]);
        int c = get<3>(test_cases[i]);

        int s_a = n / a;
        int s_b = n / b;
        int s_c = n / c;

        int s_ab = n / lcm(a, b); 
        int s_bc = n / lcm(b, c); 
        int s_ac = n / lcm(a, c); 

        int s_abc = n / lcm(a, b, c);

        int S = s_a + s_b + s_c - s_ab - s_bc - s_ac + s_abc;

        cout << S << "\n";
    }

    return 0;
}
