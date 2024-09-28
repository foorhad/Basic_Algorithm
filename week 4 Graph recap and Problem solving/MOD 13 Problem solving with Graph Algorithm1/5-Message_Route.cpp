#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

vector<int>adj_list[100005];
bool vis[100005]={false};
int parent[100005];

void bfs(int source){
    vis[source]=true;
    queue<int>q;
    q.push(source);

    while (!q.empty())
    {
        int par = q.front();q.pop();
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parent[child] = par;
            }
        }
    }
}
int main()
{
 fast();
    memset(parent,-1,sizeof(parent));
    int computers,connectios;cin>>computers>>connectios;
    while (connectios--)
    {
        int u,v;cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bfs(1);

    if(parent[computers]==-1)cout<<"IMPOSSIBLE"<<nl;
    else
    {
        int des=computers;
        vector<int>path;
        while (des!=-1)
        {
            path.push_back(des);
            des = parent[des];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<nl;
        for(int p : path)cout<<p<<" ";
    }

    return 0;
}