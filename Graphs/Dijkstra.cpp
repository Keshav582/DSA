#include <bits/stdc++.h>

using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &adjList, vector<int> &distanceFromSrc) {
    priority_queue<pair<int, int>> maxPQ;
    distanceFromSrc[src] = 0;
    maxPQ.push(make_pair(0, src));
    while (!maxPQ.empty()) {
        int currSrc = maxPQ.top().second;
        maxPQ.pop();
        for (auto edge:adjList[currSrc]) {
            int currDest = edge.first;
            int edgeWeight = edge.second;
            if (distanceFromSrc[currSrc] + edgeWeight < distanceFromSrc[currDest]) {
                distanceFromSrc[currDest] = distanceFromSrc[currSrc] + edgeWeight;
                maxPQ.push(make_pair(distanceFromSrc[currDest], currDest));
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<pair<int, int>>> adjList(numNodes + 1);
    for (int edge = 1; edge <= numEdges; edge++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        adjList[src].push_back(make_pair(dest, weight));
    }

    int src;
    cin >> src;

    vector<int> distanceFromSrc(numNodes + 1, 1e9);
    dijkstra(src, adjList, distanceFromSrc);

    cout << "minimum distance from " << src << " to every node:\n";
    for (int node = 1; node <= numNodes; node++) {
        cout << "node: " << node << "; distance: " << distanceFromSrc[node] << '\n';
    }

    return 0;
}