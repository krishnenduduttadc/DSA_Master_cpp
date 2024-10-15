#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    bool found = false;
    int target_x, target_y;
    cin>>target_x>>target_y;
    for(int i=0; i<n; i++){
        if(
            a[i]==target_x && b[i]==target_y || 
            b[i]==target_x && a[i]==target_y 
        ) found = true;
    }
    if(found)
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}

/*
4
2 3
4 5
3 5
1 7
5 3
*/