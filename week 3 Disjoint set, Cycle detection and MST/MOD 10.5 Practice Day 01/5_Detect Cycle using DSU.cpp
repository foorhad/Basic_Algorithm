//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int par[10005];  
    int sz[10005];  
    void init(int n){
        for(int i=0;i<n;i++){
            par[i]=-1;
            sz[i]=1;
        }
    }
    int find(int x){
        if(par[x]==-1)return x;
        int leader = find(par[x]);
        par[x]=leader;
        return leader;
    }
    
    void union_by_sz(int x, int y){
        int la = find(x);
        int lb = find(y);
        if(sz[la] > sz[lb]){
            par[lb]=la;
            sz[la]+=sz[lb];
        }
        else{
            par[la]=lb;
            sz[lb]+=sz[la];
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    init(V);
        set<pair<int,int>>s;
	    for(int i=0;i<V;i++)
        {
            for(int edge : adj[i])
            {
                if(edge < i)
                    s.insert({edge, i});
                else
                    s.insert({i, edge});
            }
        }
        for(auto e : s){
            if(find(e.first)==find(e.second)){
                // flag = false; 
                return 1;
            }
            else{
                union_by_sz(e.first,e.second);
            }
        }
    return 0;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
