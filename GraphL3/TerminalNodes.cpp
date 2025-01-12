#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TerminalNodes {
private:
    unordered_map<int, vector<int>> adjacencyList;

public:
    TerminalNodes() {}

    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination]; // Ensure destination is also in the map
    }

    void printTerminalNodes() {
        vector<int> terminalNodes;
        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
            if (it->second.empty()) {
                terminalNodes.push_back(it->first);
            }
        }
        cout << "Terminal Nodes:" << endl;
        for (int node : terminalNodes) {
            cout << node << endl;
        }
    }
};

int main() {
    TerminalNodes graph;

    // Adding edges to the graph
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(6, 7);

    graph.printTerminalNodes();

    return 0;
}
