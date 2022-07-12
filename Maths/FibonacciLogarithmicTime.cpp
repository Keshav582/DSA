#include <bits/stdc++.h>

using namespace std;

void mult(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    a = temp;
}

void power(vector<vector<int>> &v, int exp) {
    int n = v.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    while (exp) {
        if (exp % 2) {
            mult(res, v);
        }
        mult(v, v);
        exp /= 2;
    }
    v = res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i <= 1) {
            cout << i << ' ';
        } else {
            vector<vector<int>> multMatrix = {{0, 1},
                                               {1, 1}};
            power(multMatrix, i - 1);
            cout << multMatrix[1][1] << ' ';
        }
    }
    cout << '\n';
    return 0;
}