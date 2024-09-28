#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

int par[100005];
int grp_sz[100005];

int find(int city){
    if(par[city]==-1)return city;
    else{
        int leader = find(par[city]);
        par[city]= leader;
        return leader;
    }
}
void union_by_sz(int city1, int city2){
    int leader_city1 = find(city1);
    int leader_city2 = find(city2);
    if(grp_sz[leader_city1] > grp_sz[leader_city2]){
        par[leader_city2] = leader_city1;
        grp_sz[leader_city1]+=grp_sz[leader_city2];
    }
    else{
        par[leader_city1] = leader_city2;
        grp_sz[leader_city2]+=grp_sz[leader_city1];
    }
}
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
int main()
{
 fast();
    memset(par,-1,sizeof(par));
    memset(grp_sz,-1,sizeof(grp_sz));
    int city,roads;
    cin>>city>>roads;
 
    vector<Edge>edgelist;
    while (roads--)
    {
       ll u,v,w;
       cin>>u>>v>>w;
       edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(),edgelist.end(),cmp);

    ll total = 0;
    for(Edge edge : edgelist){
        int leader_u = find(edge.u);
        int leader_v = find(edge.v);
        if(leader_u != leader_v){
            union_by_sz(edge.u,edge.v);
            total += edge.w;
        }
    }
    bool ans = true;
    for(int i=2;i<=city;i++){
        if(find(i) != find(1))ans = false;
    }
    if(ans)cout<<total<<nl;
    else cout<<"IMPOSSIBLE";
    return 0;
}