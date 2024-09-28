//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool vis[100005];
    int par[100005];
    bool cycle = false;
    void dfs(int i,vector<int> adj[]){
        vis[i]=true;
        for(int child : adj[i]){
            if(vis[child] && par[i]!=child){
                cycle=true;
            }
            if(!vis[child]){
                par[child]=i;
                dfs(child,adj);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
      memset(par,-1,sizeof(par));
      memset(vis,false,sizeof(vis));
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj);
            }
        }
        return cycle;
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
// } Driver Code Ends