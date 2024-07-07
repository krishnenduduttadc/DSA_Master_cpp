#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator function for sorting strings in descending order
bool compare(string a, string b) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba; // Compare in descending order
}

string largestNumber(vector<int>& nums) {
    // Convert integers to strings
    vector<string> arr(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        arr[i] = to_string(nums[i]);
    }

    // Sort using custom comparator
    sort(arr.begin(), arr.end(), compare);

    // Construct the result string
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
