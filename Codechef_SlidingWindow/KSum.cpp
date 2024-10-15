#include <bits/stdc++.h>

using namespace std;

int maxSumKElements(const vector<int>& arr, int k) {
    
    int i=0;
    int n=arr.size();
    int csum=0;
    
    for (int i = 0; i < k; i++) {
       csum+=arr[i];
    }
    int osum=csum;
    for (int i = 0; i < k; i++) {
        int inclu=arr[n-1-i];
        int exclu=arr[k-1-i];
        csum=csum-exclu+inclu;
        osum=max(csum,osum);
    }
    
   
    return osum;
}

int main() {
    int n, k;
    
    cin >> n;
    cin >> k;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    cout << maxSumKElements(arr, k) << endl;
    
    return 0;
}


/*
5 3
4 2 1 5 1

*/