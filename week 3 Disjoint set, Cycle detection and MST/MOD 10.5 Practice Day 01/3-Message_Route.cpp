#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

const int N = 2e5+5;
vector<int>adj_list[N];
int parent[N];
bool vis[N]={false};

void bfs(int i){
    queue<int>q;
    q.push(i);
    vis[i]=true;
    while (!q.empty())
    {
        int par = q.front();q.pop();
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
                parent[child]=par;
            }
        }
    }   
}
int main()
{
 fast();
    int n,e;cin>>n>>e;
    while (e--)
    {
        int a,b;cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if(vis[n]){
        int des = n;
        vector<int>path;
        while (des!=-1)
        {
            path.push_back(des);
            des = parent[des];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<nl;
        for(int val : path)cout<<val<<" ";
    }
    else{
        cout<<"IMPOSSIBLE"<<nl;
    }
    
    return 0;
}