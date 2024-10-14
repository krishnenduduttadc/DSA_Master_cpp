#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int L = 0, R = n-1;
        deque<char> dq;
        while (L <= R) {
            if (s[L] == '0') dq.push_front('0');
            else dq.push_back('1');
            
            if (L < R) {
                if (s[R] == '1') dq.push_front('1');
                else dq.push_back('0');
            }
            ++L, --R;
        }
        for (auto c : dq) cout << c;
        cout << '\n';
    }
}

/*

4
2
10
4
0001
6
010111
10
1110000010
*/