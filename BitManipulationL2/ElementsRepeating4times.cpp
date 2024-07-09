#include <iostream>
#include <vector>

using namespace std;

class ElementsRepeating4times {
public:
    int findElement(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans = ans ^ arr[i];
        }
        return ans;
    }
};

int main() {
    ElementsRepeating4times solution;

    // Example input
    vector<int> arr = {2, 4, 1, 2, 4};

    int result = solution.findElement(arr);
    cout << "Element occurring exactly four times: " << result << endl; // Expected output: 1

    return 0;
}
