#include <iostream>
#include <vector>
#include <algorithm>

class Item {
public:
    int wt, val;

    Item(int w, int v) : wt(w), val(v) {}
};

bool compareItems(const Item& i1, const Item& i2) {
    return (double)i1.val / i1.wt > (double)i2.val / i2.wt;
}

double fracKnapsack(std::vector<Item>& arr, int W) {
    std::sort(arr.begin(), arr.end(), compareItems);
    double res = 0.0;
    
    for (const auto& item : arr) {
        if (item.wt <= W) {
            res += item.val;
            W -= item.wt;
        } else {
            res += ((double)item.val * W) / item.wt;
            break;
        }
    }
    return res;
}

int main() {
    std::vector<Item> arr = {
        Item(10, 60),
        Item(40, 40),
        Item(20, 100),
        Item(30, 120)
    };
    int W = 50;
    std::cout << fracKnapsack(arr, W) << std::endl;
    return 0;
}