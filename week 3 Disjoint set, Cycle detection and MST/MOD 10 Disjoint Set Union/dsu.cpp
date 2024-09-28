#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;

const int N = 1e5 + 5;
int par[N];
int sz[N];
void dsu_initial(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
    // par[2]=1;
    // par[1]=0;
    // par[5]=4;
    // par[4]=3;
}
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1); // 0
    int leaderB = dsu_find(node2); // 3
    par[leaderA] = leaderB;
}
void dsu_union_by_size(int node1, int node2)
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
    dsu_initial(n);
    // dsu_union(2,5);
    // cout << dsu_find(1) << endl;
    dsu_union_by_size(1, 2);
    dsu_union_by_size(2, 3);
    dsu_union_by_size(4, 5);
    dsu_union_by_size(6, 5);
    dsu_union_by_size(1, 4);
    cout << dsu_find(4) << endl;
    cout << dsu_find(1) << endl;
    cout<<"size: "<<sz[5]<<endl;

    return 0;
}