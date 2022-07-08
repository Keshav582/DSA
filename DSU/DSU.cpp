#include <bits/stdc++.h>

using namespace std;

int findParent(int node, vector<int> &parents) {
    if (node != parents[node]) {
        return parents[node] = findParent(parents[node], parents);
    }
    return node;
}

void makeUnion(int nodeA, int nodeB, vector<int> &parents, vector<int> &sizes) {
    int parentA = findParent(nodeA, parents);
    int parentB = findParent(nodeB, parents);
    if (parentA != parentB) {
        if (sizes[parentA] >= sizes[parentB]) {
            parents[parentB] = parentA;
            sizes[parentA] += sizes[parentB];
        } else {
            parents[parentA] = parentB;
            sizes[parentB] += sizes[parentA];
        }
    }
}

int main() {
    int numberOfNodes;
    cin >> numberOfNodes;

    vector<int> parents(numberOfNodes + 1), sizes(numberOfNodes + 1);

    for (int node = 1; node <= numberOfNodes; node++) {
        parents[node] = node;
        sizes[node] = 1;
    }

    int queries;
    cin >> queries;

    while (queries--) {
        int queryType;
        cin >> queryType;

        // queryType 1 is 'union', queryType 2 is 'print parents of all nodes'
        if (queryType == 1) {
            int nodeA, nodeB;
            cin >> nodeA >> nodeB;
            makeUnion(nodeA, nodeB, parents, sizes);
        } else {
            for (int node = 1; node <= numberOfNodes; node++) {
                cout << "node: " << node << "; parent: " << parents[node] << '\n';
            }
        }
    }

    return 0;
}