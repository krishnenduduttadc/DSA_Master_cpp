#include<bits/stdc++.h>

using namespace std;

int largest2(vector<int> arr, int n) {
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                max_len = max(max_len, j - i + 1);
            }
        }
    }

    return max_len;
}

int largest3(vector<int> arr, int n) {
    map<int, int> mapp;
    mapp[0]=-1;
    int sum=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
       sum+=arr[i];
       if(mapp.find(sum)!=mapp.end()){
        auto it=mapp[sum];
        ans=max(ans,i- it);
       }
       else{
        mapp[sum]=i;
       }
    }
    return ans;
}



int largestSubarrayWithZeroSum(vector<int> arr) {
    unordered_map<int, int> hm; // Maps sum to index
    int sum = 0;
    int max_len = 0;
    
    hm[0] = -1; // Initialize to handle the case where sum becomes 0 at the start
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if (hm.find(sum) != hm.end()) {
            int len = i - hm[sum];
            if (len > max_len) {
                max_len = len;
            }
        } else {
            hm[sum] = i;
        }
    }
    
    return max_len;
}

int main() {
    vector<int> arr = {2, 8, -3, -5, 2, -4, 6, 1, 2, 1, -3, 4};
    int max_length = largestSubarrayWithZeroSum(arr);
    cout << max_length << endl; // Output: 5

    int n=arr.size();
    int res=largest2(arr,n);
    cout<<res<<endl;

    int res3=largest3(arr,n);
    cout<<res3<<endl;
    
    return 0;
}
