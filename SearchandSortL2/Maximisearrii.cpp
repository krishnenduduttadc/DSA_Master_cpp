#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximise(vector<int>& arr) {
    int sum = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i] * i;
    }

    return sum;
}

int main() {
    vector<int> arr = {1, 4, 5, 7, 6, 2, 4};
    cout << maximise(arr) << endl;

    return 0;
}
