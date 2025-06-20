#include <iostream>
#include <string>
using namespace std;

void toggle(char ch[]) {
    for (int i = 0; ch[i] != '\0'; i++) {
        if (ch[i] >= 'A' && ch[i] <= 'Z') {
            ch[i] = ch[i] + 32; // Convert uppercase to lowercase
        } else if (ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] = ch[i] - 32; // Convert lowercase to uppercase
        }
    }
}

int main() {
    char st[] = "kriSh";
    toggle(st);
    cout << st << endl; // Output the modified string
    return 0;
}
