#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int par[N];
int grp_size[N];

void init(int n){
    for(int i=0;i<=n;i++)
        par[i]=-1,grp_size[i]=1;
}

int find(int node){
    if(par[node] == -1)return node;
    else
    {
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }
}
void Union_by_sz(int n1, int n2){
    int leaderA = find(n1);
    int leaderB = find(n2);
    if(grp_size[leaderA] > grp_size[leaderB]){
        par[leaderB] = leaderA;
        grp_size[leaderA]+=grp_size[leaderB];
    }
    else{
        par[leaderA] = leaderB;
        grp_size[leaderB]+=grp_size[leaderA];
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;
    vector<Edge>edgelist;
    while(m--){
        int u,v,w;cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(), edgelist.end(),cmp);
    init(n);

    int total_cost=0;
    for(auto group : edgelist){
        int leaderA = find(group.u) ;
        int leaderB = find(group.v);
        if(leaderA==leaderB)continue;
        else{
            Union_by_sz(leaderA,leaderB);
            total_cost+=group.w;
        } 
    }
    cout<<total_cost<<endl;
}
