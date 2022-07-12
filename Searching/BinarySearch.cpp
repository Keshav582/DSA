#include <bits/stdc++.h>

using namespace std;

// return true if target in v, else return false
bool binarySearch(vector<int> v, int target) {
    sort(v.begin(), v.end());
    int ansRangeLo = 0, ansRangeHi = v.size() - 1;
    while (ansRangeLo <= ansRangeHi) {
        int ansRangeMid = (ansRangeLo + ansRangeHi) / 2;
        if (v[ansRangeMid] == target) return true;
        if (v[ansRangeMid] < target) ansRangeLo = ansRangeMid + 1;
        if (v[ansRangeMid] > target) ansRangeHi = ansRangeMid - 1;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int target;
    cin >> target;
    cout << binarySearch(v, target) << '\n';
    return 0;
}