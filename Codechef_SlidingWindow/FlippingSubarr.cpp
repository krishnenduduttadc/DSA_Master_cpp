#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int current = 0, count = 0;
    vector<int> freq;
    for(int i=0; i<n; i++){
        if(arr[i] != current) {
            current = arr[i];
            freq.push_back(count);
            count = 0;
            
        }
        count++;
    }
    freq.push_back(count);
    long long maximum = INT_MIN;
    for(int i=0; i<freq.size(); i++){
        long long sum = 0;
        if(i%2!=0) sum = freq[i];
        else{
            sum = freq[i];
            if(i>0) sum+=freq[i-1];
            if(i<freq.size()-1) sum+=freq[i+1];
        }
        maximum = max(maximum, sum);
    }
    if(freq.size()==2 && freq[0]==0){
        cout<<n-1<<endl;
        return 0;
    }
    cout<<maximum<<endl;
    
}

/*
3
0 1 0
*/