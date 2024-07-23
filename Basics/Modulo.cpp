#include <iostream>
using namespace std;
int main()
{
    long long x=1;
    int n=5;
    int m=3;
    for (int i = 2; i <=n; i++)
    {
        x=(x*i)%m;
        
    }
    cout<< x%m;
    
}