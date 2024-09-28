#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,e;
vector<int>v[100];
bool vis[100]={false};
int c=0;
void dfs(int node){
    c++;
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
    vector<int>numberOfnodes;
    for(int i=0; i<n; i++){
        if(!vis[i]){
           dfs(i);
           numberOfnodes.push_back(c);
           c=0;
        }
    }
    sort(numberOfnodes.begin(),numberOfnodes.end());
    for(int val : numberOfnodes)cout<<val<<" ";
   
    return 0;
}