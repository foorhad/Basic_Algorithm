#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool vis[N] = {false};
int parrentArray[N];
bool ans=false;

//depth first search
void dfs(int parent){
   vis[parent]=true;
   for(int child : adj[parent]){
    if(vis[child] && parrentArray[parent]!=child){
        ans = true;
    }
    if(!vis[child]){
        parrentArray[child]=parent;
        dfs(child);
    }
   }
}
int main(){
    fast();
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(parrentArray,-1,sizeof(parrentArray));
    for (int i = 0; i < n; i++){
        if (!vis[i])dfs(i);
    }

    if(ans)cout<<"cycle found"<<endl;
    else cout<<"cycle not found"<<endl;
    return 0;
}