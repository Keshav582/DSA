#include <bits/stdc++.h>

using namespace std;
int rootMaxHeight = 20;

void dfs(int node, int par, vector<vector<int>> &adjList, vector<vector<int>> &parents, vector<int> &level) {
    parents[node][0] = par;
    level[node] = level[par] + 1;
    for (auto child:adjList[node]) {
        if (child == par) continue;
        dfs(child, node, adjList, parents, level);
    }
}

int lca(int nodeA, int nodeB, vector<int> &level, vector<vector<int>> &parents) {
    if (level[nodeA] < level[nodeB]) return lca(nodeB, nodeA, level, parents);
    int cpyRootMaxHeight;
    for (cpyRootMaxHeight = 0; (1 << cpyRootMaxHeight) <= level[nodeA]; cpyRootMaxHeight++) {

    }
    cpyRootMaxHeight--;
    for (int i = cpyRootMaxHeight; i >= 0; i--) {
        if (level[nodeA] - (1 << i) >= level[nodeB]) {
            nodeA = parents[nodeA][i];
        }
    }
    if (nodeA == nodeB) return nodeA;
    for (int i = cpyRootMaxHeight; i >= 0; i--) {
        if (parents[nodeB][i] != -1 && parents[nodeA][i] != parents[nodeB][i]) {
            nodeA = parents[nodeA][i];
            nodeB = parents[nodeB][i];
        }
    }
    return parents[nodeA][0];
}

int main() {
    int numNodes;
    cin >> numNodes;
    vector<vector<int>> adjList(numNodes + 1);
    for (int edge = 1; edge <= numNodes - 1; edge++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjList[nodeA].push_back(nodeB);
        adjList[nodeB].push_back(nodeA);
    }

    vector<int> level(numNodes + 1, -1);
    vector<vector<int>> parents(numNodes + 1, vector<int>(rootMaxHeight + 1, -1));
    dfs(1, 0, adjList, parents, level);

    int numQueries;
    cin >> numQueries;
    while (numQueries--) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        cout << lca(nodeA, nodeB, level, parents) << '\n';
    }
    return 0;
}