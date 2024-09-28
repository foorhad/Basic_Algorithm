#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
int main()
{
 fast();
    int n,e;cin>>n>>e;
    vector<int>adj_list[n];
    while (e--)
    {
        int u,v;cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<pair<int,int>>edgelist;
    for (int i = 0; i < n; i++)
    {
        for(int child : adj_list[i]){
            edgelist.push_back({i,child});
        }
    }
    for(auto group : edgelist){
        cout<<group.first<<" "<<group.second<<nl;
    }
    
    return 0;
}