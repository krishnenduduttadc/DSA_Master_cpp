#include <iostream>
using namespace std;
int main()
{
    pair<int,int> p={2,4};
    cout<<p.first<<" "<<p.second;

    pair<int,int> arr[]={{1,2},{3,4},{5,6}};
    cout<<"\n"<<arr[2].second;

    pair<int,pair<int,int>> pp={1,{2,3}};
    cout<<"\n"<<pp.second.first;
}