#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

const int N=1e5+5;
bool ans=false;
vector<int> adj[N];
bool vis[N]={false};
int parentArray[N];
void dfs(int parent){
    vis[parent]=true;
    for(int child : adj[parent]){
        if(vis[child] && parentArray[parent]!=child){
            ans = true;
        }
        if(!vis[child]){
            parentArray[child]=parent;
            dfs(child);
        }
    }
}
int main()
{
 fast();
    int n,m;cin>>n>>m;
    while (m--)
    {
       int a,b;cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    memset(parentArray,-1,sizeof(parentArray));
    for(int i=0; i<n; i++){
        if(!vis[i])dfs(i);
    }
    if(ans)cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    
    return 0;
}