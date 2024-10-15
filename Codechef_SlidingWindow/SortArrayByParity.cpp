#include <bits/stdc++.h>
using namespace std;

void sortArrayByParity(vector<int>& nums) {
    // Write your code here
    int odd_count = 0;
    for(auto num: nums){
        if(num%2!=0) odd_count++;
    }
    int left = 0, right = odd_count;
    vector<int> result(nums.size());
    for(auto num: nums){
        if(num%2==0){
            result[right] = num;
            right++;
        }
        else{
            result[left] = num;
            left++;
        }
    }
    nums = result;
    
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sortArrayByParity(nums);

    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

/*
5
3 1 2 4 5
*/