#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class OrderOfRemoval {
public:
    static int orderOfRemoval(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Sorting the array

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int temp = arr[i] * (n - i);
            ans += temp;
        }

        return ans;
    }
};

int main() {
    // Hardcoded input array
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    // Calling orderOfRemoval function to calculate the order of removal
    int result = OrderOfRemoval::orderOfRemoval(arr);

    // Printing the result
    cout << "Order of removal: " << result << endl;

    return 0;
}
