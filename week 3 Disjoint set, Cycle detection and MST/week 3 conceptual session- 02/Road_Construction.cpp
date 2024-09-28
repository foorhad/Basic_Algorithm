#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;
const int N = 1e5+5;
int par[N];
int cmp,sz;
vector<int> group_sz(N);
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1, group_sz[i] = 1;
    }
    cmp=n,sz=INT_MIN;
}
int find(int node)
{
    if (par[node] == -1)
        return node;
    else
    {
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }
}
void Union_by_size(int n1, int n2)
{
    int leaderA = find(n1);
    int leaderB = find(n2);
    if (leaderA == leaderB)return;
    if (group_sz[leaderA] > group_sz[leaderB])
    {
        par[leaderB] = leaderA;
        group_sz[leaderA] += group_sz[leaderB];
        sz = max(sz, group_sz[leaderA]);
    }
    else
    {
        par[leaderA] = leaderB;
        group_sz[leaderB] += group_sz[leaderA];
        sz = max(sz, group_sz[leaderB]);
    }
    cmp--;
}
int main()
{
    fast();
    int n, e;
    cin >> n >> e;
    init(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        Union_by_size(leaderA, leaderB);
        cout << cmp << " " << sz << nl;
    }

    return 0;
}