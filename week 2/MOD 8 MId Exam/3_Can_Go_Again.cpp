#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
ll n,e;
class Edge{
public:
    ll u,v,c;
    Edge(ll u, ll v, ll c){
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
int main()
{
 fast();
    cin>>n>>e;
    ll dis[10005];
    for(ll i=0; i<=n; i++)dis[i]=INF;
    vector<Edge> edgelist;
    while (e--)
    {
       ll a,b,w;cin>>a>>b>>w;
        edgelist.push_back({a,b,w});
    }
    ll s;cin>>s;
    dis[s]=0;

    for(ll i=0; i<n; i++){
        for(auto p : edgelist){
            int u = p.u;
            int v = p.v;
            int c = p.c;
            if(dis[u]!=INF && dis[u]+c < dis[v]){
                dis[v] = dis[u]+c;
            }
        }
    }

    for(auto p : edgelist){
        int u = p.u;
        int v = p.v;
        int c = p.c;
        if(dis[u]!=INF && dis[u]+c < dis[v]){
            cout<<"Negative Cycle Detected"<<endl;
            return 0;
        }
    }


    ll tc;cin>>tc;
    while(tc--){
        ll d;cin>>d;
        if(dis[d]==INF)cout<<"Not Possible"<<endl;
        else cout<<dis[d]<<endl;
    }
    return 0;
}