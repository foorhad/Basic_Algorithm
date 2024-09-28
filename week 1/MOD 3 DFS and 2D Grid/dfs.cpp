#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N = 1e5+5;

vector<int> adjacency_list[N];
bool vis[N]={false};

void dfs(int src){
    cout<<src<<endl;
    vis[src]=true;
    for(int child : adjacency_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main()
{
 fast();
    int n,e;cin>>n>>e;
    while (e--){
        int a,b;cin>>a>>b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }
    dfs(0);
    
    return 0;
}