#include <bits/stdc++.h>

using namespace std;

int gcd(int num1, int num2) {
    if (num1 < num2) swap(num1, num2);
    if (num2 == 0) return num1;
    return gcd(num2, num1 % num2);
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << '\n';
    return 0;
}