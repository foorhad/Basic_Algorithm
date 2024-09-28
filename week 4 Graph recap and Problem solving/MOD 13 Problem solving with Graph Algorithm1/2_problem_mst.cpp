#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
const int N = 1e5+5;
int par[N];
int grp_sz[N];

int find(int building){
    if(par[building] == -1)return building;
    else{
        int parent =  find(par[building]);
        par[building] = parent;
        return parent;
    }
}

void Union_by_size(int building1, int building2){
    int parA = find(building1);
    int parB = find(building2);

    if(grp_sz[parA] > grp_sz[parB]){
        par[parB] = parA;
        grp_sz[parA]+= grp_sz[parB];
    }
    else
    {
        par[parA] = parB;
        grp_sz[parB]+= grp_sz[parA];
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
    memset(grp_sz,1,sizeof(grp_sz));

    int building,roads;
    cin>>building>>roads;
    vector<Edge>edgelist;
    while (roads--)
    {
        int u,v,w;cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    sort(edgelist.begin(),edgelist.end(),cmp);

    //Kruskal's Algorithm
    int total_cost = 0;
    for(Edge edge : edgelist){
        int leaderU = find(edge.u);
        int leaderV = find(edge.v);
        if(leaderU!=leaderV){
            Union_by_size(edge.u,edge.v);
            total_cost+=edge.w;
        }
    }
    cout<<total_cost<<nl;
    
    return 0;
}