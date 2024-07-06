#include <iostream>
#include <queue>
#include <string>
using namespace std;

string kth(int k) {
    queue<string> q;
    q.push("1");
    q.push("2");

    string ans;
    for (int i = 0; i < k; i++) {
        string temp = q.front();
        q.pop();
        ans = temp;
        q.push(temp + "1");
        q.push(temp + "2");
    }

    return ans;
}

int main() {
    int k = 5;
    cout << kth(k) << endl;
    return 0;
}
