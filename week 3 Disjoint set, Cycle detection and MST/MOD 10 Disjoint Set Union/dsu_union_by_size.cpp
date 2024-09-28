#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;
const int N = 1e5 + 5;
int par[N];
int sz[N];
void dsu_init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union_by_sz(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (sz[leaderA] > sz[leaderB])
    {
        par[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    fast();
    int n;
    cin >> n;
    dsu_init(n);
    dsu_union_by_sz(1, 2);
    dsu_union_by_sz(1, 6);
    dsu_union_by_sz(4, 5);
    dsu_union_by_sz(3, 4);
    dsu_union_by_sz(2, 4);
    cout << "parent of 1 :" << dsu_find(1) << endl;
    cout << "parent of 6 :" << dsu_find(6) << endl;
    cout << "parent of 4 :" << dsu_find(4) << endl;
    cout << "parent of 2 :" << dsu_find(2) << endl;
    // cout << sz[2] << endl;

    return 0;
}