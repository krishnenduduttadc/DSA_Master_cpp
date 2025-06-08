#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void addEdge(unordered_map<int, vector<int>>& adj, int source, int destination) {
    adj[source].push_back(destination);
    // Ensure destination is in the map, even if it has no outgoing edges
    if (adj.find(destination) == adj.end()) {
        adj[destination] = vector<int>();
    }
}

void printTerminalNodes(const unordered_map<int, vector<int>>& adj) {
    cout << "Terminal Nodes:" << endl;
    for (unordered_map<int, vector<int>>::const_iterator it = adj.begin(); it != adj.end(); ++it) {
        if (it->second.empty()) {
            cout << it->first << endl;
        }
    }
}

int main() {
    unordered_map<int, vector<int>> adjacencyList;

    // Add edges to the graph
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 2, 3);
    addEdge(adjacencyList, 3, 4);
    addEdge(adjacencyList, 4, 5);
    addEdge(adjacencyList, 6, 7);

    printTerminalNodes(adjacencyList);

    return 0;
}
