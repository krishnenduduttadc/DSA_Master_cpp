#include <iostream>
#include <vector>
using namespace std;

class ProductOfArrayExceptItself {
public:
    static vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // Calculating left products
        int left = 1;
        for (int i = 1; i < n; i++) {
            left *= nums[i - 1];
            res[i] *= left;
        }

        // Calculating right products and multiplying with left products
        int right = 1;
        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            res[i] *= right;
        }

        return res;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    vector<int> res = ProductOfArrayExceptItself::productExceptSelf(arr);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
