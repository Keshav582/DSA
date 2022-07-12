#include <bits/stdc++.h>
using namespace std;
string preprocess(string &s) {
    if(s=="") return "^$";
    string ans = "^";
    for(auto itr:s) {
        ans+="#";
        ans+=itr;
    }
    ans+="#$";
    return ans;
}
string lps(string &s) {
    string t = preprocess(s);
    int n = t.size();
    int R = 0, C = 0;
    int P[n];
    for(int i=1;i+1<n;i++) {
        int i_mirror = 2*C-i;
        P[i] = (R>i ? min(P[i_mirror], R-i) : 0);
        while(t[i+1+P[i]]==t[i-1-P[i]]) P[i]++;
        if(i+P[i]>R) {
            C = i;
            R = i+P[i];
        }
    }
    int maxLen = 0, centerIdx = 0;
    for(int i=1;i+1<n;i++) {
        if(maxLen<P[i]) {
            maxLen = P[i];
            centerIdx = i;
        }
    }
    return s.substr((centerIdx-maxLen-1)/2, maxLen);
}
int main() {
    string s; cin >> s;
    cout << lps(s) << '\n';
    return 0;
}