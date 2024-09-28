#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
bool vis[N];
void dfs(int i)
{
    vis[i] = true;
    for (int child : adj_list[i])
    {
        if (!vis[child])
            dfs(child);
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
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            v.push_back(i);
            dfs(i);
        }
    }
    cout << v.size() - 1 << nl;
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i - 1] << " " << v[i] << nl;
    }

    return 0;
}