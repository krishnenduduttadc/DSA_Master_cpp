#include <iostream>
#include <vector>
using namespace std;

void nextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << nge[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    nextGreaterElements(arr);

    return 0;
}


/*
4
4 5 2 10
*/