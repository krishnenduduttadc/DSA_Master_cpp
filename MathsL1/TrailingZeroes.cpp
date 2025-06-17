#include <iostream>
using namespace std;

static void main()
{
    int res = 0;
    int n = 7;
    for (int i = 5; i <= n; i = i * 5)
    {
        res = res + n / i;
    }
    cout << "zeroes: " << res << endl;
}

int main()
{
    main();
    return 0;
}
