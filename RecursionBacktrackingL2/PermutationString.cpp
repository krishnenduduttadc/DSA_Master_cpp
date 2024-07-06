#include <iostream>
#include <unordered_map>
using namespace std;

void generate(int cs, int ts, unordered_map<char, int>& fmap, string asf) {
    if (cs > ts) {
        cout << asf << endl;
        return;
    }

    for (auto entry : fmap) {
        char ch = entry.first;
        int count = entry.second;
        
        if (count > 0) {
            fmap[ch]--;
            generate(cs + 1, ts, fmap, asf + ch);
            fmap[ch]++;
        }
    }
}

int main() {
    string str = "abc";
    unordered_map<char, int> fmap;

    for (char ch : str) {
        fmap[ch]++;
    }

    generate(1, str.length(), fmap, "");

    return 0;
}
