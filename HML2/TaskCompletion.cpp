#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void taskCompletion(int n, const vector<int>& arr) {
    unordered_set<int> completed(arr.begin(), arr.end());

    vector<int> one, two;
    bool flag = true;

    for (int i = 1; i <= n; i++) {
        if (completed.find(i) == completed.end()) {
            if (flag) {
                one.push_back(i);
            } else {
                two.push_back(i);
            }
            flag = !flag;
        }
    }

    for (int val : one) cout << val << " ";
    cout << endl;
    for (int val : two) cout << val << " ";
    cout << endl;
}

int main() {
    int n = 156;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    taskCompletion(n, arr);

    return 0;
}
