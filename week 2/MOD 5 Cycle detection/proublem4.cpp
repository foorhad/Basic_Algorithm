// problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool ans;
    bool vis[100005]={false};
    bool pathArray[100005]={false};
    
    void dfs(int parent,vector<int> adj[]){
        vis[parent]=true;
        pathArray[parent]=true;
        
        for(int child : adj[parent]){
            if(pathArray[child]){
                ans = true;
            }
            if(!vis[child]){
                dfs(child,adj);
            }
        }
    pathArray[parent]=false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        ans = false;
        for(int i=0; i<V; i++){
            if(!vis[i])dfs(i,adj);
        }
    return ans;
        
    }
};



int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

