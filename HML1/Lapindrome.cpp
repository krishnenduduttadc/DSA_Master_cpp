#include <bits/stdc++.h>

using namespace std;


bool isLapindrome(string s) {
    int len = s.length();
    vector < int > countLeft(26, 0), countRight(26, 0);
    for (int i = 0; i < len/2; i++) {
        countLeft[s[i]-'a']++;
    }
    for (int i = (len+1)/2; i < len; i++) {
        countRight[s[i] - 'a']++;
    }
    if(countLeft==countRight){
        return true;
    }else{
        return false;
    }
}

int main() {
    int T;
   
    vector < string > testCases={"gaga","abcde","rotor","xyzxy","abbaab","ababc"};

    


    for (string s: testCases) {
        int len = s.length();
        if (isLapindrome(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}