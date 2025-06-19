#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int divide(int A, int B)
{
    int sign = 1;
    if (A < 0)
    {
        sign = sign * -1;
    }
    if (B < 0)
    {
        sign = sign * -1;
    }

    long long a = abs(static_cast<long long>(A));
    long long b = abs(static_cast<long long>(B));

    long long res = 0;
    long long t = 0;

    for (int x = 31; x >= 0; x--)
    {
        if ((t + (b << x)) <= a)
        {
            res += (static_cast<long long>(1) << x);
            t += b << x;
        }
    }

    if (sign < 0)
    {
        res = -res;
    }

    if (res > numeric_limits<int>::max())
    {
        return numeric_limits<int>::max();
    }
    else if (res < numeric_limits<int>::min())
    {
        return numeric_limits<int>::min();
    }
    else
    {
        return static_cast<int>(res);
    }
}

int main()
{

    // Test cases
    int A1 = 10;
    int B1 = 3;
    int result1 = divide(A1, B1);
    cout << "Result of " << A1 << " / " << B1 << " = " << result1 << endl; // Expected output: 3

    return 0;
}
