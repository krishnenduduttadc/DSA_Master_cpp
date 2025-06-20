#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int totalLength = m + n;
    vector<int> merged(totalLength);

    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k] = nums1[i];
            i++;
        } else {
            merged[k] = nums2[j];
            j++;
        }
        k++;
    }

    while (i < m) {
        merged[k] = nums1[i];
        i++;
        k++;
    }

    while (j < n) {
        merged[k] = nums2[j];
        j++;
        k++;
    }

    double median = 0.0;
    int mid = totalLength / 2;
    if (totalLength % 2 == 1) {
        median = merged[mid];
    } else {
        median = (merged[mid] + merged[mid - 1]) / 2.0;
    }

    return median;
}

int main() {
    vector<int> arr1 = {3, 5, 7, 10, 15};
    vector<int> arr2 = {2, 4, 12};

    double median = findMedianSortedArrays(arr1, arr2);
    cout << "Median of the two sorted arrays: " << median << endl;

    return 0;
}
