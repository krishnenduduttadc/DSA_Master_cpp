#include <iostream>
#include <vector>
using namespace std;

class CoinChangeCombination2 {
public:
    static void coinChange(int i, vector<int>& coins, int amtsf, int tamt, string asf) {
        if (i == coins.size()) {
            if (amtsf == tamt) {
                cout << asf << "." << endl;
            }
            return;
        }

        for (int j = tamt / coins[i]; j >= 1; j--) {
            string part = "";
            for (int k = 0; k < j; k++) {
                part += to_string(coins[i]) + "-";
            }
            coinChange(i + 1, coins, amtsf + coins[i] * j, tamt, asf + part);
        }
        coinChange(i + 1, coins, amtsf, tamt, asf);
    }
};

int main() {
    vector<int> coins = {2, 3, 5, 6, 7};
    int amt = 12;
    CoinChangeCombination2::coinChange(0, coins, 0, amt, "");
    return 0;
}
