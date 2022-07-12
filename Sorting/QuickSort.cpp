#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int l, int r) {
    swap(v[r], v[l + rand() % (r - l)]);
    int pivot = v[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return (i + 1);
}

void quicksort(vector<int> &v, int l, int r) {
    if (l < r) {
        int pivot = partition(v, l, r);
        quicksort(v, l, pivot - 1);
        quicksort(v, pivot + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    quicksort(v, 0, n - 1);
    for (auto itr:v) cout << itr << ' ';
    cout << '\n';
    return 0;
}