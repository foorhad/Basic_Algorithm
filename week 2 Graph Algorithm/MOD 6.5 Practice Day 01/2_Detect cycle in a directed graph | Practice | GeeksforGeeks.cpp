//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool flag;
    bool vis[100005];
    bool path[100005];
    void dfs(int src,vector<int> adj[]){
        vis[src]=true;
        path[src]=true;
        
        for(int child : adj[src]){
            if(path[child])flag=true;
        
            if(!vis[child]){
                dfs(child,adj);
            }
        }
        path[src]=false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        flag =false;
        memset(vis,false,sizeof(vis));
        memset(path,false,sizeof(path));
        for(int i=0;i<V;i++){
            if(!vis[i])dfs(i,adj);   
        }
        return flag;
    }
};

//{ Driver Code Starts.

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

// } Driver Code Ends
