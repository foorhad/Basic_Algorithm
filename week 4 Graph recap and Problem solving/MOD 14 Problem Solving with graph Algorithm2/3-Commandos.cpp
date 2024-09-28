#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

vector<int>adj_list[110];
bool vis[110];
int dest[110];
int dest1[110];
void bfs(int src){
    vis[src]=true;
    dest[src]=0;
    queue<int>q;
    q.push(src);

    while (!q.empty())
    {
        int par = q.front();q.pop();
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                dest[child]=dest[par]+1;
            }
        }
    }
}
void bfs1(int d){
    vis[d]=true;
    dest1[d]=0;
    queue<int>q;
    q.push(d);

    while (!q.empty())
    {
        int par = q.front();q.pop();
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                dest1[child]=dest1[par]+1;
            }
        }
    }
}
int main()
{
 fast();
    int tc;cin>>tc;
    for (int s = 1; s <= tc; s++)
    {
        int n,r;cin>>n>>r;
        while (r--)
        {
            int u,v;cin>>u>>v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int src,des;cin>>src>>des;
        memset(vis,false,sizeof(vis));
        memset(dest,-1,sizeof(dest));
        bfs(src);
        memset(vis,false,sizeof(vis));
        memset(dest1,-1,sizeof(dest1));
        bfs1(des);
        
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i] = dest[i]+dest1[i];
        }
        cout<<"Case "<<s<<": "<<*max_element(v.begin(),v.end())<<nl;
        for(int i=0;i<110;i++){
            adj_list[i].clear();
        }
    }
    
    return 0;
}