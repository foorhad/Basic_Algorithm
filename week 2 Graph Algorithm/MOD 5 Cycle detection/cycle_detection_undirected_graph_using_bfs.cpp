#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 1e5+5;

vector<int> adj[N];

bool vis[N] = {false};
int parrentArray[N];

bool ans=false; //checking cycle ace naki nai

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty()){
        int parent = q.front();
        q.pop();
        for (int child : adj[parent]){
            if(vis[child] && parrentArray[parent]!=child){
                ans=true;
                break;
            }
            if (!vis[child]){
                parrentArray[child]=parent;
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
int main()
{
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
        if (!vis[i])bfs(i);
    }
    if(ans)cout<<"cycle found"<<endl;
    else cout<<"cycle not found"<<endl;
    return 0;
}