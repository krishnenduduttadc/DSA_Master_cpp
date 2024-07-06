#include <iostream>
#include <string>
using namespace std;

long long poly_hash(const string& s) {
    long long hash = 0;
    long long p = 31;
    long long mod = 1e9 + 7;
    long long p_power = 1;

    for (int i = 0; i < s.length(); i++) {
        hash = (hash + (s[i] - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }

    return hash;
}

int main() {
    string s = "abaasdasdasfasasfaba";
    cout << "Hash value: " << poly_hash(s) << endl;
    return 0;
}
