#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> generate(int N) {
    vector<string> ans;
    queue<string> q;
    q.push("1");
    while (N-- > 0) {
        string rem = q.front();
        q.pop();
        ans.push_back(rem);
        q.push(rem + "0");
        q.push(rem + "1");
    }
    return ans;
}

int main() {
    int N = 5;
    vector<string> binaryNumbers = generate(N);
    for (string num : binaryNumbers) {
        cout << num << endl;
    }
    return 0;
}
