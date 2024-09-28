#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,e;
vector<int>v[100];
bool vis[100]={false};

void dfs(int node){
    vis[node]=true;
    for(auto child : v[node]){
        if(!vis[child])dfs(child);
    }
}
int main()
{
 fast();
    cin>>n>>e;
    while(e--){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int components=0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            components++;
            dfs(i);
        }
    }
    cout<<components<<endl;
   
    return 0;
}