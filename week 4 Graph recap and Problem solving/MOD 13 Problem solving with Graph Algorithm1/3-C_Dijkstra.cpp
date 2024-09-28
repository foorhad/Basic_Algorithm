#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll> 
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

vector<pi> adj_list[N];
bool vis[N] = {false};
ll par[N];
ll dis[N];

void dijkstra(ll source)
{
    vis[source] = true;
    dis[source] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0,source});

    while (!pq.empty())
    {
        pi parent = pq.top();
        pq.pop();

        int par_node = parent.second;
        int par_cost = parent.first;

        for(pi child : adj_list[par_node])
        {
            int child_node = child.second;
            int child_cost = child.first;

            //path relax
            if(dis[par_node]+child_cost < dis[child_node]){
                dis[child_node] = dis[par_node]+child_cost;
                vis[child_node] = true;
                par[child_node] = par_node;
                pq.push({dis[child_node],child_node});
            }
        }
    }
}
int main()
{
    fast();
    memset(par, -1, sizeof(par));
    ll n, m;cin >> n >> m;
    for(int i=1;i<=n;i++)dis[i]=INF;
    while (m--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        adj_list[u].push_back({c, v});
        adj_list[v].push_back({c, u});
    }
   dijkstra(1);
    if(vis[n]){
        ll des = n;
        vector<ll>path;
        while (des!=-1)
        {
            path.push_back(des);
            des = par[des];
        }
        reverse(path.begin(),path.end());
        for(int v:path)cout<<v<<" ";  
    }
    else{
        cout<<-1<<nl;
    }
  

    return 0;
}