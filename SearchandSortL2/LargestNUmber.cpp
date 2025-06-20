#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba; // Compare in descending order
}

string largestNumber(vector<int>& nums) {
    vector<string> arr(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        arr[i] = to_string(nums[i]);
    }

    sort(arr.begin(), arr.end(), compare);

    if (arr[0] == "0") { // Special case to handle if all nums are zeroes
        return "0";
    }
    
    string result;
    for (const string& s : arr) {
        result += s;
    }
    
    return result;
}

int main() {
    vector<int> nums = {3, 7, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    
    return 0;
}
