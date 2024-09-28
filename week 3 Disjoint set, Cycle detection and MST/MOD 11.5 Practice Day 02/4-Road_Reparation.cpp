#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
const int N = 1e5 + 5;

int par[N];
int level[N];
void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = -1, level[i] = 0;
}
int find(int node)
{
    if (par[node] == -1)
        return node;
    else
    {
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }
}
void Union_by_level(int n1, int n2)
{
    int leaderA = find(n1);
    int leaderB = find(n2);
    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderB] = leaderA;
        level[leaderA]++;
    }
}

class Edge{
public: 
    ll u,v,w;
    Edge(ll u,ll v,ll w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int main()
{
 fast();
    vector<Edge> edgelist;
    ll n,m;cin>>n>>m;
    while (m--)
    {
        ll u,v,w;cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(),edgelist.end(),cmp);
  
    init(n);
    ll total_cost=0;
    for(auto group : edgelist){
        ll leaderA= find(group.u);
        ll leaderB= find(group.v);
        if(leaderA == leaderB)continue;
        else{
            Union_by_level(leaderA,leaderB);
            total_cost+=group.w;
        }
    }
    
    bool ans = true;
    for(int i=1;i<=n;i++){
        if(find(1)!=find(i))ans=false;
    }
    if(ans)cout<<total_cost<<nl;
    else cout<<"IMPOSSIBLE";
    return 0;
}