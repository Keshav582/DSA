#include <bits/stdc++.h>

using namespace std;

vector<int> low, in;
vector<bool> visited;
vector<vector<int>> adjList;
set<pair<int, int>> bridges;
int timer;

void dfs(int node, int par) {
    visited[node] = true;
    low[node] = in[node] = timer;
    timer++;
    for (auto child:adjList[node]) {
        if (child == par) continue;
        if (visited[child]) {
            low[node] = min(low[node], in[child]);
        } else {
            dfs(child, node);
            if (low[child] > in[node]) {
                bridges.insert({min(node, child), max(node, child)});
            }
            low[node] = min(low[node], low[child]);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    timer = 0;
    adjList.resize(nodes + 1, vector<int>());
    low.resize(nodes + 1, -1);
    in.resize(nodes + 1, -1);
    visited.resize(nodes + 1, false);

    for (int edge = 1; edge <= edges; edge++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjList[nodeA].push_back(nodeB);
        adjList[nodeB].push_back(nodeA);
    }

    dfs(1, -1);

    for (auto edge:bridges) {
        cout << edge.first << " <-> " << edge.second << " is a bridge\n";
    }

    return 0;
}