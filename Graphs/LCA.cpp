// Nodes start from node 1
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
vector<vector<int>> adj(N);
const int LG = 20;

// lvl[i] -> level of node i, lvl[1] = 0;
// P[i][j] -> (2^j)th parent of node i
int lvl[N], P[N][LG];

void dfs(int u, int par) {
    lvl[u] = 1 + lvl[par];
    P[u][0] = par;
    for (auto itr:adj[u]) {
        if (itr == par) {
            continue;
        }
        dfs(itr, u);
    }
}

int lca(int u, int v) {
    int lg;
    if (lvl[u] < lvl[v]) {
        swap(u, v);
    }

    for (lg = 0; (1 << lg) <= lvl[u]; lg++);
    lg--;

    for (int i = lg; i >= 0; i--) {
        if (lvl[u] - (1 << i) >= lvl[v]) {
            u = P[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (int i = lg; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i], v = P[v][i];
        }
    }

    return P[u][0];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < LG; i++) {
        for (int j = 0; j <= n; j++) {
            P[j][i] = -1;
        }
    }
    lvl[0] = -1;

    dfs(1, 0);

    for (int i = 1; i < LG; i++) {
        for (int j = 1; j <= n; j++) {
            if (P[j][i - 1] != -1) {
                P[j][i] = P[P[j][i - 1]][i - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
