#include <iostream>
#include <vector>
using namespace std;

static void coinChange(int i, vector<int> &coins, int amtsf, int tamt, string asf)
{
    if (i == coins.size())
    {
        if (amtsf == tamt)
        {
            cout << asf << "." << endl;
        }
        return;
    }

    coinChange(i + 1, coins, amtsf + coins[i], tamt, asf + to_string(coins[i]) + "-");
    coinChange(i + 1, coins, amtsf + 0, tamt, asf);
}

static void start()
{
    vector<int> coins = {2, 3, 5, 6, 7};
    int amt = 12;
    coinChange(0, coins, 0, amt, "");
}

int main()
{
    start();
    return 0;
}
