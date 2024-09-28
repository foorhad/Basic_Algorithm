#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int> ar[1005];
bool vis[1005] = {false};
int level[1005];
void bfs()
{
    queue<int> q;
    q.push(0);
    vis[0] = true;
    level[0] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : ar[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
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
    memset(level, -1, sizeof(level));
    int l;cin>>l;
    bfs();
    vector<int> v;
    for(int i=0; i<n; i++){
        if(level[i] == l){
           v.push_back(i);
        }
    }
    reverse(v.begin(),v.end());
    for(int i : v)cout<<i<<" ";
    return 0;
}