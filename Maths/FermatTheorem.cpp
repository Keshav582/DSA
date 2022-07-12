// Theorem ---> (a^(-1))%mod == (a^(mod-2))%mod
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

int fermat(int num, int mod) {
    return power(num, mod - 2, mod);
}

int main() {
    int num, mod;
    cin >> num >> mod;
    cout << fermat(num, mod) << '\n';
    return 0;
}