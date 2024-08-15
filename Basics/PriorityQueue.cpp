#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq; //max heap
    pq.push(5);
    pq.push(2);
    pq.push(3);
    cout<<pq.top();


    priority_queue<int,vector<int>,greater<int>> pqm; //min heap
    pqm.push(5);
    pqm.push(2);
    pqm.push(3);
    cout<<"\n"<<pqm.top();
}