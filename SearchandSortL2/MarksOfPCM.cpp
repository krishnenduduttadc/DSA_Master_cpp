#include <bits/stdc++.h>

using namespace std;

// Define a struct-like comparator function
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int phy1 = get<0>(a), chem1 = get<1>(a), math1 = get<2>(a);
    int phy2 = get<0>(b), chem2 = get<1>(b), math2 = get<2>(b);

    if (phy1 != phy2) {
        return phy1 < phy2;
    } else if (chem1 != chem2) {
        return chem1 > chem2; // Descending chem
    } else {
        return math1 < math2;
    }
}

// Function to custom sort marks
void customSort(vector<int>& phy, vector<int>& chem, vector<int>& math) {
    int n = phy.size();
    vector<tuple<int, int, int>> arr;

    // Combine all marks into a tuple list
    for (int i = 0; i < n; ++i) {
        arr.emplace_back(phy[i], chem[i], math[i]);
    }

    // Sort using custom comparator
    sort(arr.begin(), arr.end(), compare);

    // Unpack sorted values back into original arrays
    for (int i = 0; i < n; ++i) {
        tie(phy[i], chem[i], math[i]) = arr[i];
    }
}

int main() {
    const int N = 5;
    vector<int> phy = {9, 5, 9, 8, 5};
    vector<int> chem = {3, 4, 3, 7, 6};
    vector<int> math = {15, 10, 11, 13, 12};

    // Call custom sort function
    customSort(phy, chem, math);

    // Output sorted marks
    for (int i = 0; i < N; ++i) {
        cout << phy[i] << " " << chem[i] << " " << math[i] << endl;
    }

    return 0;
}
