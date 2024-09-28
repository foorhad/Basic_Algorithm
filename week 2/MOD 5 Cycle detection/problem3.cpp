// problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool ans;
    bool vis[100005]={false};
    int parentArray[100005];
    
    void dfs(int parent, vector<int> adj[]){
        vis[parent]=true;
        for(int child : adj[parent]){
            
            if(vis[child] && parentArray[parent]!=child){
                ans = true;
            }
            if(!vis[child]){
                parentArray[child]=parent;
                dfs(child,adj);
            }
        }
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        memset(parentArray,-1,sizeof(parentArray));
        ans = false;
        for(int i=0; i<V; i++){
            if(!vis[i])dfs(i,adj);
        }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
