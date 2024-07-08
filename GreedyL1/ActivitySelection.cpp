#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Activity {
public:
    int start;
    int finish;
    
    Activity(int s, int f) : start(s), finish(f) {}
};

struct MyCmp {
    bool operator()(const Activity& a1, const Activity& a2) const {
        return a1.finish < a2.finish;
    }
};

int maxActivity(vector<Activity>& arr) {
    sort(arr.begin(), arr.end(), MyCmp());
    int res = 1;
    int prev = 0;
    for (int curr = 1; curr < arr.size(); curr++) {
        if (arr[curr].start >= arr[prev].finish) {
            res++;
            prev = curr;
        }
    }
    return res;
}

int main() {
    vector<Activity> arr = {Activity(12, 25), Activity(10, 20), Activity(20, 30)};
    cout << maxActivity(arr) << endl;
    return 0;
}
