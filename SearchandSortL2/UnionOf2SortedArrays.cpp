#include <iostream>
#include <vector>

using namespace std;

vector<int> unionOfArrays(int a[], int b[], int m, int n) {
    vector<int> unionList;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (unionList.empty() || unionList.back() != a[i]) {
                unionList.push_back(a[i]);
            }
            i++;
        } else if (b[j] < a[i]) {
            if (unionList.empty() || unionList.back() != b[j]) {
                unionList.push_back(b[j]);
            }
            j++;
        } else {
            if (unionList.empty() || unionList.back() != a[i]) {
                unionList.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while (i < m) {
        if (unionList.empty() || unionList.back() != a[i]) {
            unionList.push_back(a[i]);
        }
        i++;
    }

    while (j < n) {
        if (unionList.empty() || unionList.back() != b[j]) {
            unionList.push_back(b[j]);
        }
        j++;
    }

    return unionList;
}

int main() {
    int a[] = {1, 2, 4};
    int b[] = {3, 5, 6};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);

    vector<int> unionList = unionOfArrays(a, b, m, n);

    for (int i = 0; i < unionList.size(); i++) {
        cout << unionList[i] << " ";
    }
    cout << endl;

    return 0;
}
