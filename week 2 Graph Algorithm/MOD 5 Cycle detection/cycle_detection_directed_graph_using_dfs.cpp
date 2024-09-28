#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int N = 1e5;

int cnt=0;
vector<int> adj[N];

bool vis[N] = {false};
bool pathvisit[N]={false};
bool ans=false;

void dfs(int parent){

   vis[parent]=true;
   pathvisit[parent]=true;
   for(int child : adj[parent]){

    if(pathvisit[child]){
        ans = true;
    }
    if(!vis[child]){
        dfs(child);
    }
   }
   pathvisit[parent]=false;
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
    }

    //component call
    for (int i = 0; i < n; i++){
        if (!vis[i])dfs(i);
    }

    if(ans)cout<<"cycle found"<<endl;
    else cout<<"cycle not found"<<endl;
    return 0;
}