#include <bits/stdc++.h>
using namespace std;

bool isSub(string s1,string s2){
    int j=0;
    for (int i = 0; i < s2.length() && j<s1.length(); i++) {
        if(s1[j]==s2[i]){
            j++;
        }
    }
    return (j==s1.length());
}

int main() {
int T; // Number of test cases
    cin >> T;
    while (T--) {
        string M, W;
        cin >> M >> W; // Input the pair of strings M and W

        if(isSub(M,W)|| isSub(W,M)){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }

}



/*
3
john johanna
ira ira
kayla jayla

*/