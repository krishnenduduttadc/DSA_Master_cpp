#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TaskCompletion {
public:
    static void complete(int n, int m, const std::vector<int>& arr) {
        unordered_set<int> comp;
        for (int val : arr) {
            comp.insert(val);
        }
        
        bool flag = true;
        vector<int> one, two;
        
        for (int i = 1; i <= n; i++) {
            if (comp.find(i) == comp.end()) {
                if (flag) {
                    one.push_back(i);
                } else {
                    two.push_back(i);
                }
                flag = !flag;
            }
        }
        
        for (int val : one) {
            cout << val << " ";
        }
        cout << std::endl;
        
        for (int val : two) {
            cout << val << " ";
        }
        cout << std::endl;
    }
};

int main() {
    int n = 156;
    int m = 256794;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    TaskCompletion::complete(n, m, arr);
    return 0;
}