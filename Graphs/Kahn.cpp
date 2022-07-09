#include <bits/stdc++.h>

using namespace std;

void toposort(vector<vector<int>> &adjList, vector<int> &indegrees, vector<int> &topologicalOrder, int numNodes) {
    queue<int> q;
    for (int i = 1; i <= numNodes; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topologicalOrder.push_back(node);
        for (auto neighbor:adjList[node]) {
            indegrees[neighbor]--;
            if (indegrees[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> adjList(numNodes + 1);
    vector<int> indegrees(numNodes + 1, 0);
    for (int edge = 1; edge <= numEdges; edge++) {
        int src, dest;
        cin >> src >> dest;
        adjList[src].push_back(dest);
        indegrees[dest]++;
    }
    vector<int> topologicalOrder;
    toposort(adjList, indegrees, topologicalOrder, numNodes);
    for (auto node:topologicalOrder) cout << node << ' ';
    cout << '\n';
    return 0;
}