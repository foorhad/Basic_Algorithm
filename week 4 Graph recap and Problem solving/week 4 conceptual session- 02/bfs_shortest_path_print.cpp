#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;
vector<int>adj_list[N];
bool vis[N];
int par_path[N];

void bfs(int i){
    vis[i]=true;
    queue<int>q;
    q.push(i);

    while (!q.empty())
    {
        int parent = q.front();q.pop();
        for(int child : adj_list[parent]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                par_path[child]=parent;
            }
        }
    }
}
int main()
{
 fast();
    memset(vis,false,sizeof(vis));
    memset(par_path,-1,sizeof(par_path));
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int u,v,c;cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bfs(1);
    int des=n;
    while (des!=-1)
    {
       cout<<des<<nl;
       des=par_path[des];
    }
    
    // cout<<par_path[4];
    
    
    return 0;
}