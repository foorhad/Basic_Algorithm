#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

class Edge{
public: 
    int u,v,w;
    Edge(int u, int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

int main()
{
 fast();
    int n,e;cin>>n>>e;
    vector<pair<int,int>>adj_list[n];
    while (e--)
    {
        int u,v,w;cin>>u>>v>>w;
        adj_list[u].push_back({v,w});
        // adj_list[v].push_back({u,w});
    }
    vector<Edge>edgelist;
    for (int i = 0; i < n; i++)
    {
        for(auto child : adj_list[i]){
           edgelist.push_back(Edge(i,child.first,child.second));
        }
    }
    for(auto group : edgelist){
        cout<<group.u<<" "<<group.v<<" "<<group.w<<nl;
    }
    
    return 0;
}