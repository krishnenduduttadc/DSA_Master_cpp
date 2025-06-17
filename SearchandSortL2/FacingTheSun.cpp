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
    // Hardcoded input
    int n = 6;
    vector<int> ht = {7, 4, 8, 2, 9, 6};

    // Call the countBuildings function to count buildings facing the sun
    int result = countBuildings(ht);

    // Print the result
    cout << "Number of buildings facing the sun: " << result << endl;

    return 0;
}
