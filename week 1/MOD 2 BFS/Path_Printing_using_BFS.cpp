#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> ar[1005];
bool vis[1005] = {false};
int level[1005];
int parent[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);
    level[src] = 0;
    vis[src] = true;

    while (!q.empty()){
        int par = q.front();q.pop();
        for (int child : ar[par])
        {
            if (vis[child] == false){
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(parent, -1, sizeof(parent));
    memset(level, -1, sizeof(level));

    // bfs(src);
    bfs(1);

    int des;
    cin >> des;
    int x = des;
    vector<int> path;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";

    return 0;
}