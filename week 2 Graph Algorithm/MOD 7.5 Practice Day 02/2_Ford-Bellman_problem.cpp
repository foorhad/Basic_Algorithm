#include <bits/stdc++.h>
using namespace std;
class Edge{
public: 
    int u,v,c;
    Edge(int u, int v, int c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int e = m;
    vector<Edge> edgelist;

    while(m--){
        int u,v,c;cin>>u>>v>>c;
        edgelist.push_back(Edge(u,v,c));
    }
    
    int dis[n+1];
    for(int i=1; i<=n; i++)dis[i]=30000;
    dis[1]=0;
    for(int i=1; i<n;i++){
        for(auto child : edgelist){
            int u = child.u;
            int v = child.v;
            int c = child.c;
            if(dis[u] < 30000 && dis[u]+c < dis[v]){
                dis[v] = dis[u]+c;
            }
        }
    }
    if(e!=0)for(int i=1; i<=n; i++)cout<<dis[i]<<" ";
    
}
