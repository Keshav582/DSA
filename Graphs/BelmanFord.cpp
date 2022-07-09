#include <bits/stdc++.h>

using namespace std;

void belmanFord(int src, vector<tuple<int, int, int>> &edges, vector<int> &distancesFromSrc) {
    distancesFromSrc[src] = 0;
    for (int turn = 1; turn <= edges.size() - 1; turn++) {
        for (auto edge:edges) {
            int currSrc = get<0>(edge);
            int currDest = get<1>(edge);
            int edgeWeight = get<2>(edge);
            distancesFromSrc[currDest] = min(distancesFromSrc[currDest], distancesFromSrc[currSrc] + edgeWeight);
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<tuple<int, int, int>> edges(numEdges);
    for (int edge = 0; edge < numEdges; edge++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges[edge] = make_tuple(src, dest, weight);
    }
    int src;
    cin >> src;
    vector<int> distanceFromSrc(numNodes + 1);

    belmanFord(src, edges, distanceFromSrc);

    cout << "Minimum distance of all nodes from " << src << ":\n";
    for (int node = 1; node <= numNodes; node++) {
        cout << "node: " << node << "; distance: " << distanceFromSrc[node] << '\n';
    }
    return 0;
}