#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int lo, int mid, int hi) {
    vector<int> left, right;
    for (int i = lo; i <= mid; i++) left.push_back(v[i]);
    for (int i = mid + 1; i <= hi; i++) right.push_back(v[i]);
    int leftPtr = 0, rightPtr = 0, vPtr = lo;
    while (leftPtr < left.size() && rightPtr < right.size()) {
        if (left[leftPtr] <= right[rightPtr]) {
            v[vPtr++] = left[leftPtr++];
        } else {
            v[vPtr++] = right[rightPtr++];
        }
    }
    while (leftPtr < left.size()) {
        v[vPtr++] = left[leftPtr++];
    }
    while (rightPtr < right.size()) {
        v[vPtr++] = right[rightPtr++];
    }
}

void mergesort(vector<int> &v, int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        mergesort(v, lo, mid);
        mergesort(v, mid + 1, hi);
        merge(v, lo, mid, hi);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    mergesort(v, 0, n - 1);
    for (auto itr:v) cout << itr << ' ';
    cout << '\n';
    return 0;
}
