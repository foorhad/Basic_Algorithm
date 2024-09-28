#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;

const int N = 2e5 + 5;
int par[N];
int grp_sz[N];

int find(int building)
{
    if (par[building] == -1)
        return building;
    else
    {
        int parent = find(par[building]);
        par[building] = parent;
        return parent;
    }
}

void Union_by_size(int building1, int building2)
{
    int parA = find(building1);
    int parB = find(building2);

    if (grp_sz[parA] > grp_sz[parB])
    {
        par[parB] = parA;
        grp_sz[parA] += grp_sz[parB];
    }
    else
    {
        par[parA] = parB;
        grp_sz[parB] += grp_sz[parA];
    }
}

int main()
{
    fast();
    memset(par, -1, sizeof(par));
    memset(grp_sz, 1, sizeof(grp_sz));

    int building, roads;
    cin >> building >> roads;
 
    while (roads--)
    {
        int u, v;
        cin >> u >> v;
        int leaderU = find(u);
        int leaderV = find(v);
        if(leaderU != leaderV)Union_by_size(u, v);
    }

    vector<int> vec;
    for (int i = 1; i <= building; i++)
    {
       vec.push_back(find(i));
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    cout<<vec.size()-1<<nl;

    for(int i=0;i<vec.size()-1;i++){
        cout<<vec[i]<<" "<<vec[i+1]<<nl;
    }

    return 0;
}