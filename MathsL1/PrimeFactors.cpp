#include <iostream>
using namespace std;

static void start()
{
    int n = 26;
    int n2 = 2;

    while (n2 * n2 <= n)
    {
        while (n % n2 == 0)
        {
            n = n / n2;
            cout << n2 << " ";
        }
        n2++;
    }

    if (n != 1)
    {
        cout << n << " ";
    }
}

int main()
{
    start();
    return 0;
}
