#include <bits/stdc++.h>
using namespace std;
int level[1005];
vector<int>ar[1005]; //adjacency list
bool vis[1005]={false}; 

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while (!q.empty())
    {
       int par = q.front();q.pop();
    //    cout<<par<<" ";

       for(auto child : ar[par]){
        if(vis[child] == false){
            q.push(child);
            vis[child]=true;
            level[child]=level[par]+1;
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
    memset(level,-1,sizeof(level));
    bfs(src);
    
    for (int i = 0; i < n ; i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    
    
    return 0;
}