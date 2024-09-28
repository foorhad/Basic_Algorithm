#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<int>v[1005];
bool vis[1005]={false};
void dfs(int src){
    cout<<src<<endl;
    vis[src]=true;
    for(auto child : v[src]){
        if(vis[child]==false){
            dfs(child);
        }
    }
}
int main()
{
 fast();
    int n,e;cin>>n>>e;
    while ((e--))
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);        
        v[b].push_back(a);        
    }
    int cmp=0;
    for(int i=0; i<n; i++){
        if(vis[i]==false){
            cmp++;
            dfs(i);
        }
    }
    cout<<"component: "<<cmp<<endl;
    return 0;
}