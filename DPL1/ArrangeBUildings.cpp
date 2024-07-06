#include <iostream>

using namespace std;

int main() {
    long long n = 5; // Replace with the desired value of n

    long long ob = 1; // Number of ways to arrange buildings ending with a building on the opposite side
    long long os = 1; // Number of ways to arrange buildings ending with a building on the same side

    for (long long i = 2; i <= n; i++) {
        long long nb = os; // New count of buildings ending with a building on the opposite side
        long long ns = os + ob; // New count of buildings ending with a building on the same side

        os = ns;
        ob = nb;
    }

    long long total = os + ob;
    total = total * total; // Total arrangements considering both sides of the road

    cout << total << endl;

    return 0;
}
