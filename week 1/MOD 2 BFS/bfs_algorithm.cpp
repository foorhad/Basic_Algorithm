#include <bits/stdc++.h>
using namespace std;
vector<int>ar[1005]; //adjacency list
bool vis[1005]={false}; 

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while (!q.empty())
    {
       int par = q.front();q.pop();
       cout<<par<<" ";

       for(auto child : ar[par]){
        if(vis[child] == false){
            q.push(child);
            vis[child]=true;
        }
       }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    while (e--)
    {
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int src;cin>>src;
    bfs(src);
    
    return 0;
}