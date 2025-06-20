#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string FirstNonRepeating(string A)
{
    queue<char> q;
    unordered_map<char, int> hm;
    string ans(A.length(), '#');

    for (int i = 0; i < A.length(); i++)
    {
        char c = A[i];

        q.push(c);
        hm[c]++;

        while (!q.empty() && hm[q.front()] > 1)
        {
            q.pop();
        }

        if (!q.empty())
        {
            ans[i] = q.front();
        }
    }

    return ans;
}

int main()
{
    string A = "aabc";
    string result = FirstNonRepeating(A);
    cout << result << endl;
    return 0;
}
