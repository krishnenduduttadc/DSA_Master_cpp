#include <iostream>
using namespace std;

class BasicMath {
public:
    static int countDigits(int n) {
        int cnt = 0;
        while (n != 0) {
            n = n / 10;
            cnt++;
        }
        return cnt;
    }

    static int countDigitsR(int n) {
        if (n == 0) {
            return 0;
        } else {
            return 1 + countDigitsR(n / 10);
        }
    }

    static bool isPalindrome(int n) {
        int temp = n;
        int rev = 0;
        while (temp != 0) {
            int ld = temp % 10;
            rev = rev * 10 + ld;
            temp = temp / 10;
        }
        return (rev == n);
    }

    static int factI(int x) {
        int f = 1;
        for (int i = 2; i <= x; i++) {
            f = f * i;
        }
        return f;
    }

    static int factR(int n) {
        if (n == 0) {
            return 1;
        }
        return n * factR(n - 1);
    }

    static int countTrailingZeroes(int n) {
        int res = 0;
        for (int i = 5; i <= n; i = i * 5) {
            res = res + n / i;
        }
        return res;
    }

    static int gcd(int a, int b) {
        while (a != b) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
        return a;
    }

    static int gcdR(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcdR(b, a % b);
        }
    }

    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    static bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    static int power(int x, int n) {
        if (n == 0) {
            return 1;
        }
        int temp = power(x, n / 2);
        temp = temp * temp;
        if (n % 2 == 0) {
            return temp;
        } else {
            return temp * x;
        }
    }

    static void primefactors(int n) {
        if (n <= 1) {
            return;
        }
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                cout << i << " ";
                n = n / i;
            }
        }
        if (n > 1) {
            cout << n;
        }
        cout << endl;
    }
};

int main() {
    cout << BasicMath::countDigits(123) << endl;
    cout << BasicMath::countDigitsR(123) << endl;
    cout << BasicMath::isPalindrome(12321) << endl;
    cout << BasicMath::factI(5) << endl;
    cout << BasicMath::factR(5) << endl;
    cout << BasicMath::countTrailingZeroes(251) << endl;
    cout << BasicMath::gcd(100, 200) << endl;
    cout << BasicMath::gcdR(100, 200) << endl;
    cout << BasicMath::lcm(100, 200) << endl;
    cout << BasicMath::isPrime(14) << endl;
    cout << BasicMath::power(2, 6) << endl;
    BasicMath::primefactors(91);

    return 0;
}
