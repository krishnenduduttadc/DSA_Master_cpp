#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<pair<int, int>> v;
    v.push_back({1, 5});
    v.push_back({2, 3});
    v.push_back({1, 2});
    v.push_back({2, 2});
    v.push_back({3, 4});

    sort(v.begin(),v.end());

   for ( auto p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

}