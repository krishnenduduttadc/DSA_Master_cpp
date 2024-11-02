#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4; // Hardcoded size of the vectors
    vector<int> a = {2, 4, 3, 1}; // Hardcoded values for vector a
    vector<int> b = {3, 5, 5, 7}; // Hardcoded values for vector b

    int target_x = 5; // Hardcoded target x value
    int target_y = 3; // Hardcoded target y value

    bool found = false;

    for(int i = 0; i < n; i++) {
        if(
            a[i] == target_x && b[i] == target_y || 
            b[i] == target_x && a[i] == target_y 
        ) 
            found = true;
    }

    if(found) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
