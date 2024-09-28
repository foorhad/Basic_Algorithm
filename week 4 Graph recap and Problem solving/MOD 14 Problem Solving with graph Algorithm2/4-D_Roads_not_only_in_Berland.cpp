#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int par[1005];
int grp_sz[1005];
int find(int n){
    if(par[n]==-1)return n;
    else
    {
        int leader = find(par[n]);
        par[n] = leader;
        return leader;
    }
}
void Union_by_sz(int n1, int n2){
    int leader_n1 = find(n1);
    int leader_n2 = find(n2);

    if(grp_sz[leader_n1]  > grp_sz[leader_n2]){
        par[leader_n2] =  leader_n1;
        grp_sz[leader_n1] += grp_sz[leader_n2];
    }
    else{
        par[leader_n1] =  leader_n2;
        grp_sz[leader_n2] += grp_sz[leader_n1];
    }
}

int main()
{
 fast();
    memset(par,-1,sizeof(par));
    memset(grp_sz,1,sizeof(grp_sz));
    int n;cin>>n;
    int r = n-1; 
    vector<pi>reject,rebuild_roads;
    while (r--)
    {
        int u,v;cin>>u>>v;
        int leader_u = find(u);
        int leader_v = find(v);
        if(leader_u==leader_v){
            reject.push_back({u,v});
        }
        else
        {
            Union_by_sz(u,v);
        } 
    }
    for (int i = 1; i <= n; i++)
    {
        int main_leader = find(1);
        int leader = find(i);
        if(main_leader!=leader){
            rebuild_roads.push_back({1,i});
            Union_by_sz(1,i);
        }
    }
    
    cout<<reject.size()<<nl;
    for (int i = 0; i < reject.size(); i++)
    {
        cout<<reject[i].first<<" "<<reject[i].second<<" "<<rebuild_roads[i].first<<" "<<rebuild_roads[i].second<<nl;

    }
    
    
    
    return 0;
}