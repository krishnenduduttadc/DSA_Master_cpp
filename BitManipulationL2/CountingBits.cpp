#include <iostream>

using namespace std;

bool checkbit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int setBits(int N) {
    int ans = 0;

    for(int i = 0; i < 32; i++) {
        if(checkbit(N, i)) {
            ans++;
        }
    }

    return ans;
}



int main() {
    cout << setBits(7) << endl;
    return 0;
}
