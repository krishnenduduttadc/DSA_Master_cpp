#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Initialize an array to store n integers
    vector < int > arr(n);

    // Read the elements of the array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<long long> prefix(n);
    prefix[0]=arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    int count=0;
    
    for (int i = 0; i < n; i++) {
       for (int j = i; j < n; j++) {
           int sum;
           if(i==0){
               sum=prefix[j];
           }else {
               sum=prefix[j]-prefix[i-1];
           }
           
            if (sum == k) count++;
       }
    }
    
    cout << count << endl;

}

/*
3 1
1 0 3
*/