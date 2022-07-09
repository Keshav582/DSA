#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto child:adjList[node]) {
        if (!visited[child]) {
            dfs(child, adjList, visited, st);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[node] = true;
    cout << node << ' ';
    for (auto child:adjList[node]) {
        if (!visited[child]) {
            revDfs(child, adjList, visited);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> adjList(numNodes + 1), transposeAdjList(numNodes + 1);
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cin >> src >> dest;
        adjList[src].push_back(dest);
        transposeAdjList[dest].push_back(src);
    }

    stack<int> st;
    vector<bool> visited(numNodes + 1, false);

    dfs(1, adjList, visited, st);

    for (int node = 1; node <= numNodes; node++) visited[node] = false;
    while (!st.empty()) {
        int startPoint = st.top();
        st.pop();
        if (visited[startPoint]) continue;
        cout << "SCC:\n";
        revDfs(startPoint, transposeAdjList, visited);
        cout << '\n';
    }

    return 0;
}