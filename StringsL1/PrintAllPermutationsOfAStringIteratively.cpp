#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solution(string str) {
    int n = str.length();
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }

    sort(str.begin(), str.end()); // Sort the string to get lexicographically smallest permutation
    for (int i = 0; i < f; i++) {
        string current_permutation = str;
        int temp = i;

        for (int div = n; div >= 1; div--) {
            int q = temp / div;
            int r = temp % div;
            swap(current_permutation[r], current_permutation[div - 1]);
            temp = q;
        }

        cout << current_permutation << endl;
    }
}

int main() {
    string str = "abc";
    solution(str);
    return 0;
}
