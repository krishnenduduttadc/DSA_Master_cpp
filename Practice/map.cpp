#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> mymap;
    mymap["krish"] = 36;
    mymap["arpita"] = 34;
    mymap["tapan"] = 68;
    mymap["amal"] = 69;
    mymap.insert(make_pair("david", 40));

    cout << "All elements in the map:" << std::endl;

    for (auto pair : mymap)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
    auto it = mymap.find("tapan");
    cout << it->first << it->second << endl;
    cout << endl;

    // Removing an element
    mymap.erase("amal");
    for (auto pair : mymap)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    mymap.clear();

    return 0;
}