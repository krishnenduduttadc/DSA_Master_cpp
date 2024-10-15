#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        sort(v.begin(), v.end());
        
        int boast_count = 0;
        for (int i = 0; i < n; i++) {
            int count_less_equal = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
            int count_greater = n - count_less_equal;
            
            if (count_less_equal > count_greater)
                boast_count++;
        }
        
        cout << boast_count << '\n';
    }
    return 0;

}


/*
3
3
100 100 100
3
2 1 3
4
30 1 30 30


*/