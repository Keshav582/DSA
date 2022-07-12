#include <bits/stdc++.h>

using namespace std;

int power(int base, int exponent, int mod) {
    int res = 1;
    while (exponent) {
        if (exponent % 2 == 1) {
            res = (res * base) % mod;
        }
        exponent /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    int base, exponent, mod;
    cin >> base >> exponent >> mod;
    cout << power(base, exponent, mod) << '\n';
    return 0;
}