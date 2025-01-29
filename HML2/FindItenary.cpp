#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main() {
    unordered_map<string, string> map;
    map["Chennai"] = "Banglore";
    map["Bombay"] = "Delhi";
    map["Goa"] = "Chennai";
    map["Delhi"] = "Goa";

    

    // Create a hashmap to mark if a city is a potential source
    unordered_map<string, bool> psrc;

    
    for (auto it = map.begin(); it != map.end(); ++it) {
        string src = it->first;
        string dest = it->second;
        
        psrc[dest] = false; // Destination city cannot be a source

        if (psrc.find(src) == psrc.end()) {
            psrc[src] = true; // Source city if it is not a destination in the map
            
        }
        
        
    }
    
    

    string src = "";
    for (auto it = psrc.begin(); it != psrc.end(); ++it) {
        if (it->second == true) {
            src = it->first;
            break;
        }
    }

    // Print the itinerary
    while (true) {
        if (map.find(src) != map.end()) {
            cout << src << " -> ";
            src = map[src];
        } else {
            cout << src << ". ";
            break;
        }
    }

    return 0;
}
