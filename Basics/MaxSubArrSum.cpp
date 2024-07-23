#include <iostream>
using namespace std;
int main()
{
    int arr[]={-1,2,4,-3,5,2,-5,2};
    int n=8;
    int best=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=max(arr[i],sum+arr[i]);
        best=max(best,sum);
    }
    cout<<best;
    
}