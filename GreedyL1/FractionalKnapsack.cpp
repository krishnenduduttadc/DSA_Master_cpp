#include <iostream>
#include <algorithm>
using namespace std;

class Item {
public:
    int wt, val;

     Item(int w, int v) {
        wt = w;
        val = v;
    }

    bool operator<(const Item& i) const {
        return (double)val / wt > (double)i.val / i.wt;
    }
};

double fracKnapsack(Item arr[], int n, int W) {
    sort(arr, arr + n);
    double res = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].wt <= W) {
            res += arr[i].val;
            W -= arr[i].wt;
        } else {
            res += (arr[i].val * (double)W) / arr[i].wt;
            break;
        }
    }
    return res;
}

int main() {
    Item arr[] = {Item(10, 60), Item(40, 40), Item(20, 100), Item(30, 120)};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 50;
    cout << fracKnapsack(arr, n, W) << endl;
    return 0;
}
