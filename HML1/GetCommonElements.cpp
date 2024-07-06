#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void getCommonElements(int a1[], int a2[], int n1, int n2) {
    unordered_map<int, int> hm; // HashMap to store element frequencies from a1

    // Count frequencies of elements in a1
    for (int i = 0; i < n1; i++) {
        hm[a1[i]]++;
    }

    // Find common elements and print them
    vector<int> commonElements;
    for (int i = 0; i < n2; i++) {
        if (hm.find(a2[i]) != hm.end() && hm[a2[i]] > 0) {
            commonElements.push_back(a2[i]);
            hm[a2[i]]--; // Decrement the count in HashMap
        }
    }

    // Print the common elements
    for (int elem : commonElements) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    int a1[] = {5, 5, 9, 8, 5, 5, 8, 0, 3};
    int a2[] = {9, 7, 1, 0, 3, 6, 5, 9, 1, 1, 8, 0, 2, 4, 2, 9, 1, 5};

    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    getCommonElements(a1, a2, n1, n2);

    return 0;
}
