#include <iostream>
using namespace std;

static int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

static void start()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = gcd(ans, arr[i]);
    }

    if (ans == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

int main()
{
    start();
    return 0;
}
