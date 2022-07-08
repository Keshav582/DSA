#include <bits/stdc++.h>

using namespace std;

vector<int> in, low;
vector<bool> visited;
vector<vector<int>> adjList;
set<int> articulationPoints;
int timer;

void dfs(int node, int par) {
    visited[node] = true;
    in[node] = low[node] = timer;
    timer++;
    int children = 0;
    for (auto child:adjList[node]) {
        if (child == par) continue;
        if (visited[child]) {
            low[node] = min(low[node], in[child]);
        } else {
            dfs(child, node);
            if (low[child] >= in[node] && par != -1) {
                articulationPoints.insert(node);
            }
            low[node] = min(low[node], low[child]);
            children++;
        }
    }
    if (par == -1 && children > 1) {
        articulationPoints.insert(node);
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    adjList.resize(nodes + 1, vector<int>());
    in.resize(nodes + 1, -1);
    low.resize(nodes + 1, -1);
    visited.resize(nodes + 1, false);
    timer = 0;

    for (int edge = 1; edge <= edges; edge++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjList[nodeA].push_back(nodeB);
        adjList[nodeB].push_back(nodeA);
    }

    dfs(1, -1);

    cout << "Articulation Points:\n";
    for (auto itr:articulationPoints) cout << itr << ' ';
    cout << '\n';

    return 0;
}