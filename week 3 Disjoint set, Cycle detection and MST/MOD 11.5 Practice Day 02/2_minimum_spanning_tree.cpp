//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Edge{
public:
    int u,v,w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
class Solution
{
	public:
	int par[1005];
	int grp_sz[1005];
	
	int find(int n){
	    if(par[n]==-1)return n;
	    else{
	        int leader = find(par[n]);
	        par[n]=leader;
	        return leader;
	    }
	}
	void Union_by_sz(int n1, int n2){
	    int leaderA = find(n1);
	    int leaderB = find(n2);
	    if(grp_sz[leaderA] > grp_sz[leaderB]){
	        par[leaderB] = leaderA;
	        grp_sz[leaderA]+=grp_sz[leaderB];
	    }
	    else{
	        par[leaderA] = leaderB;
	        grp_sz[leaderB]+=grp_sz[leaderA];
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        memset(par,-1,sizeof(par));
        memset(grp_sz,1,sizeof(grp_sz));
        vector<Edge>edgelist;
        
        for(int u=0;u<V;u++){
            for(auto vec : adj[u]){
                int v = vec[0];
                int w = vec[1];
                edgelist.push_back(Edge(u,v,w));
            }
        }
        sort(edgelist.begin(),edgelist.end(),cmp);
        int total_cost = 0;
        for(Edge edge : edgelist){
            int leaderU = find(edge.u);
            int leaderV = find(edge.v);
            if(leaderU==leaderV)continue;
            else{
                 Union_by_sz(edge.u,edge.v);
                 total_cost += edge.w;
            }
        }
    return total_cost;
    }
};

//{ Driver Code Starts.
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends