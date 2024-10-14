#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    deque<int> dq;
	    for (int i = 0; i < n; ++i) {
	        int x; cin >> x;
	        dq.push_back(x);
	    }
	    int ans = 0;
	    while (dq.size() > 1) {
	        int x = dq.front(), y = dq.back();
	        dq.pop_front(); dq.pop_back();
	        if (x == y) continue;
	        ++ans;
	        if (x < y) dq.push_back(y-x);
	        else dq.push_front(x-y);
	    }
	    cout << ans << '\n';
	}
	return 0;
}

/*
3
4
3 7 6 4
5
1 4 5 4 1
5
1 2 3 4 5


*/