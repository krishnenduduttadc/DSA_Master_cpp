#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a class to represent marks
class Marks {
public:
    int phy;
    int chem;
    int math;

    // Constructor
    Marks(int p, int c, int m) : phy(p), chem(c), math(m) {}

    // Method to compare for sorting
    bool operator<(const Marks& other) const {
        if (phy != other.phy) {
            return phy < other.phy;
        } else if (chem != other.chem) {
            return chem > other.chem; // Sort chem descending if phy are equal
        } else {
            return math < other.math;
        }
    }
};

// Function to custom sort marks
void customSort(vector<int>& phy, vector<int>& chem, vector<int>& math) {
    int n = phy.size();
    vector<Marks> arr;

    // Populate the vector of Marks objects
    for (int i = 0; i < n; ++i) {
        arr.emplace_back(phy[i], chem[i], math[i]);
    }

    // Sort using overloaded < operator in Marks class
    sort(arr.begin(), arr.end());

    // Update original arrays with sorted values
    for (int i = 0; i < n; ++i) {
        phy[i] = arr[i].phy;
        chem[i] = arr[i].chem;
        math[i] = arr[i].math;
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
