#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Job {
public:
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit)
        : id(id), deadline(deadline), profit(profit) {}
};

struct JobComparator {
    bool operator()(const Job& j1, const Job& j2) {
        if (j1.profit != j2.profit)
            return j2.profit < j1.profit;
        else
            return j2.deadline < j1.deadline;
    }
};

void printJobScheduling(std::vector<Job>& jobs) {
    std::sort(jobs.begin(), jobs.end(), JobComparator());

    std::set<int> ts;
    for (int i = 0; i < jobs.size(); i++)
        ts.insert(i);

    for (const auto& job : jobs) {
        auto it = ts.upper_bound(job.deadline - 1);
        if (it != ts.begin()) {
            --it;
            std::cout << job.id << " ";
            ts.erase(it);
        }
    }
}

int main() {
    std::vector<Job> jobs = {
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15)
    };

    printJobScheduling(jobs);
    std::cout << std::endl;

    return 0;
}