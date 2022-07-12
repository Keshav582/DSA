#include <bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(string &s) {
    int n = s.size();
    vector<int> v(n, 0);
    for (int i = 1; i < n; i++) {
        int j = v[i - 1];
        while (j > 0 && s[j] != s[i]) j = v[j - 1];
        if (s[i] == s[j]) j++;
        v[i] = j;
    }
    return v;
}

void kmp(string &text, string &pattern, vector<int> &matchingIndices) {
    vector<int> prefixVector = prefixFunction(pattern);
    int textPtr = 0, patPtr = 0;
    while (textPtr < text.size()) {
        if (text[textPtr] == pattern[patPtr]) {
            patPtr++;
            textPtr++;
        } else {
            if (patPtr != 0) {
                patPtr = prefixVector[patPtr - 1];
            } else {
                textPtr++;
            }
        }
        if (patPtr == pattern.size()) {
            matchingIndices.push_back(textPtr - pattern.size());
            patPtr = prefixVector[patPtr - 1];
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> matchingIndices;
    kmp(text, pattern, matchingIndices);
    for (auto itr:matchingIndices) cout << itr << ' ';
    cout << '\n';
    return 0;
}