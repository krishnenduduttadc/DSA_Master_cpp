#include <iostream>
#include <vector>
using namespace std;

static int countBuildings(vector<int> &ht)
{
    int lmax = ht[0];
    int count = 1;

    for (int i = 1; i < ht.size(); i++)
    {
        if (ht[i] > lmax)
        {
            count++;
            lmax = ht[i];
        }
    }

    return count;
}

int main()
{
    int n = 6;
    vector<int> ht = {7, 4, 8, 2, 9, 6};

    int result = countBuildings(ht);

    cout << "Number of buildings facing the sun: " << result << endl;

    return 0;
}
