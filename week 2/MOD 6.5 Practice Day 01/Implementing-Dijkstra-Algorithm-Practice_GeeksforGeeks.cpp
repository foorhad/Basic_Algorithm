//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dis;
        for(int i=0; i<V; i++)dis.push_back(INT_MAX);
        
        queue<pair<int,int>>q;
        q.push({S,0});
        dis[S]=0;
        
        while(!q.empty()){
            pair<int,int>p = q.front();q.pop();
            int parentNode = p.first;
            int parentCost = p.second;
            
            for(auto child : adj[parentNode]){
            int childNode = child[0];
            int childCost = child[1];
            
            if(parentCost+childCost < dis[childNode]){
                dis[childNode] = parentCost+childCost;
                q.push({childNode,dis[childNode]});
                }
            }
        }
    return dis;
    }
};




int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

