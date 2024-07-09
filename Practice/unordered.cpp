#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
   unordered_map<string, int> unorderedMap;

    // Inserting elements into the map
    
    unorderedMap["Bob"] = 25;
    unorderedMap["Charlie"] = 35;
    unorderedMap["Alice"] = 30;

    // Displaying elements (unordered)
    cout << "Elements in the unordered map:" << endl;
    for (const auto pair : unorderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }


    return 0;
}
