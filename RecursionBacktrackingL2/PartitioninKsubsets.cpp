#include <iostream>
#include <vector>

using namespace std;

int counter = 0;

void solution(int i, int n, int k, int nos, vector<vector<int>>& ans) {
    if (i > n) {
        if (nos == k) {
            counter++;
            cout << counter << ". ";
            for (auto& set : ans) {
                cout << "[";
                for (auto num : set) {
                    cout << num << " ";
                }
                cout << "] ";
            }
            cout << endl;
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++) {
        if (!ans[j].empty()) {
            ans[j].push_back(i);
            solution(i + 1, n, k, nos, ans);
            ans[j].pop_back();
        } else {
            ans[j].push_back(i);
            solution(i + 1, n, k, nos + 1, ans);
            ans[j].pop_back();
            break;
        }
    }
}

int main() {
    int n = 4;
    int k = 3;
    vector<vector<int>> ans(k);

    solution(1, n, k, 0, ans);

    return 0;
}
