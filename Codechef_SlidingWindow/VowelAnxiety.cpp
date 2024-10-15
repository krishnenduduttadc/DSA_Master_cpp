#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        // Vowels set
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        vector<char> result(n);
        int left = 0;
        int right = n - 1;
        bool startFromLeft = false;
        
        // Traverse from end to start
        for(int i = n - 1; i >= 0; i--) {
            if(startFromLeft) {
                result[left++] = s[i];
            } else {
                result[right--] = s[i];
            }
            
            if(vowels.count(s[i]) > 0) {
                startFromLeft = !startFromLeft;
            }
        }
        
        for(int i = 0; i < n; i++) {
            cout << result[i];
        }
        cout << '\n';
    }

    return 0;

}


/*
2
10
abcdefghij
7
bcadage
*/