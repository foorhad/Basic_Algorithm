#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,e;
vector<int>ar[10005];
bool vis[1005]={false};

void bfs(int src){
    vis[src]=true;
    for(int child : ar[src]){
        vis[child]=true;
    }
}
int main()
{
 fast();
   cin>>n>>e;
    while (e--)
    {
        int a,b;cin>>a>>b;
        ar[a].push_back(b);
    }
    int q;cin>>q;
    while (q--)
    {
        int x,y;cin>>x>>y;
        bfs(x);
        if(vis[y])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        memset(vis,false,sizeof(vis));
    }
    
    
    return 0;
}