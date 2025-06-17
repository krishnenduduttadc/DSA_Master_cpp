#include <iostream>
using namespace std;

static void start()
{
    int n = 10;

    for (int i = 0; i < n / 2; i++)
    {
        cout << 2 * i + 1 << " " << 2 * i + 2 << endl;
    }
}

int main()
{
    start();
    return 0;
}
