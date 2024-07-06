#include <iostream>
using namespace std;

int solution(int n, int k) {
    if (n == 1) {
        return 0;
    }
    int x = solution(n - 1, k);
    int y = (x + k) % n;
    return y;
}

int main() {
    int n = 4;
    int k = 2;
    cout << solution(n, k) << endl;
    return 0;
}
