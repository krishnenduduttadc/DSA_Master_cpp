#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ll a = 1234567;
    ll b = 12345;

    cout << a + b <<endl;

    vi vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    for (auto i = 0; i < vi.size(); i++)
    {
        cout<<vi[i]<<endl;
    }
    

}