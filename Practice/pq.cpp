#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    while (!pq.empty())
    {
        int r=pq.top();
        cout<< r << endl;
        pq.pop();
    }
    return 0;
}