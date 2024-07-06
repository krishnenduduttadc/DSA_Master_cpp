#include <iostream>
#include <vector>
#include <algorithm>

class Activity {
public:
    int start;
    int finish;
    
    Activity(int s, int f) : start(s), finish(f) {}
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.finish < a2.finish;
}

class ActivitySelectionProblem {
public:
    static int maxActivity(std::vector<Activity>& arr) {
        std::sort(arr.begin(), arr.end(), compareActivities);
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
};

int main() {
    std::vector<Activity> arr = {
        Activity(12, 25),
        Activity(10, 20),
        Activity(20, 30)
    };
    std::cout << ActivitySelectionProblem::maxActivity(arr) << std::endl;
    return 0;
}