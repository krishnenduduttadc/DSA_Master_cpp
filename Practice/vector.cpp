#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for (int it : v) {
        cout << it << endl;
    }

    cout << endl;

    for (int i = 0; i < v.size(); i++)
    {
        v[i]=i*i;
        cout<< v[i] << endl;
    }
    

    return 0;
}