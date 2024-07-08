#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& ans, int n, int& temp) {
    if (n == 0) {
        ans.push_back(temp);
        return;
    }

    backtrack(ans, n - 1, temp);

    temp = temp ^ (1 << (n - 1));
    backtrack(ans, n - 1, temp);
}

vector<int> grayCode(int n) {
    vector<int> ans;
    if (n == 0) {
        ans.push_back(0);
        return ans;
    }
    
    int temp = 0;
    backtrack(ans, n, temp);
    return ans;
}

int main() {
    vector<int> ans = grayCode(3);
    sort(ans.begin(), ans.end());
    
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
