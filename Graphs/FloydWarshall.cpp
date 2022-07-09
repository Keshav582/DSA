#include <bits/stdc++.h>

using namespace std;

void floydWarshall(vector<vector<int>> &allPairDistances, int numNodes) {
    for (int intermediate = 1; intermediate <= numNodes; intermediate++) {
        for (int src = 1; src <= numNodes; src++) {
            for (int dest = 1; dest <= numNodes; dest++) {
                allPairDistances[src][dest] = min(allPairDistances[src][dest], allPairDistances[src][intermediate] +
                                                                               allPairDistances[intermediate][dest]);
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<int>> allPairDistances(numNodes + 1, vector<int>(numNodes + 1, 1e9));
    for (int node = 1; node <= numNodes; node++) allPairDistances[node][node] = 0;
    for (int edge = 1; edge <= numEdges; edge++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        allPairDistances[src][dest] = weight;
    }
    floydWarshall(allPairDistances, numNodes);
    for (int src = 1; src <= numNodes; src++) {
        for (int dest = 1; dest <= numNodes; dest++) {
            cout << "Minimum distance from " << src << " to " << dest << " is: " << allPairDistances[src][dest] << '\n';
        }
    }
    return 0;
}