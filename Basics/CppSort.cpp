#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vi = {-1, 2, 4, -3, 5, 2, -5, 2};
    
    sort(vi.begin(),vi.end());
    for (int i = 0; i < vi.size(); i++)
    {
        cout <<" "<< vi[i];
    }
    cout << endl;

    int arr[]={5,6,4,8,2,1};
    int n = 6;
    sort(arr,arr+n);

    for (int i = 0; i < n; i++)
    {
        cout <<" "<< arr[i];
    }

    cout << endl;
    string s="monkey";
    sort(s.begin(),s.end());
    cout<<s;
}