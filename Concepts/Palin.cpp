#include <bits/stdc++.h>
using namespace std;

bool palin(string aa)
{
    int i = 0;
    int j = aa.size() - 1;

    while (i < j)
    {
        if (aa[i] != aa[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    string aa = "abba";
    bool res = palin(aa);
    cout << res << endl;  // Will print 0 if not palindrome, 1 if it is
}
