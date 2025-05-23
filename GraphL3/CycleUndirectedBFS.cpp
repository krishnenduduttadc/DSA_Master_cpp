#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool detect(int s, vector<int> adj[], int vis[]) {
      vis[s] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({s, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto it: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[it]) {
                  vis[it] = 1; 
                  q.push({it, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != it) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}