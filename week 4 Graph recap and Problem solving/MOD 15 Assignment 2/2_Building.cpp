#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long llINF = 1e18+5;
const ll N = 1e6 + 5;
using namespace std;
ll par[N];
ll grp_sz[N];
int find(ll n){
    if(par[n]==-1)return n;
    else{
        ll leader = find(par[n]);
        par[n] =  leader;
        return leader;
    }
}
void Union_by_sz(ll n1, ll n2){
    ll leader_n1 = find(n1);
    ll leader_n2 = find(n2);

    if(grp_sz[leader_n1] > grp_sz[leader_n2]){
        par[leader_n2] =  leader_n1;
        grp_sz[leader_n1]+=grp_sz[leader_n2];
    }
    else
    {
        par[leader_n1] =  leader_n2;
        grp_sz[leader_n2]+=grp_sz[leader_n1];
    }
}
class Edge{
public: 
    ll u,v,c;
    Edge(ll u,ll v, ll c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
bool cmp(Edge a, Edge b){
    return a.c < b.c;
}
int main()
{
 fast();
    memset(par,-1,sizeof(par));
    memset(grp_sz,1,sizeof(grp_sz));
    ll n,e;cin>>n>>e;
    vector<Edge>edgelist;
    while (e--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(),edgelist.end(),cmp);

    ll total_cost = 0;
    for(Edge edge : edgelist){
       ll leader_u = find(edge.u);
       ll leader_v = find(edge.v);

       if(leader_u != leader_v){
        Union_by_sz(edge.u,edge.v);
        total_cost += edge.c; 
       }
    }
    bool flag = true;
    for(int i=2;i<=n;i++){
        int leadera = find(1);
        int leaderb = find(i);
        if(leadera!=leaderb)flag=false;
    }
    if(flag)cout<<total_cost<<nl;
    else cout<<-1<<nl;
    
    return 0;
}