#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;

const int N = 1e5+5;
int par[N];
int grp_sz[N];

int find(int building){
    if(par[building] == -1)return building;
    else{
        int parent =  find(par[building]);
        par[building] = parent;
        return parent;
    }
}

void Union_by_size(int building1, int building2){
    int parA = find(building1);
    int parB = find(building2);

    if(grp_sz[parA] > grp_sz[parB]){
        par[parB] = parA;
        grp_sz[parA]+= grp_sz[parB];
    }
    else
    {
        par[parA] = parB;
        grp_sz[parB]+= grp_sz[parA];
    } 
}

int main()
{
 fast();
    memset(par,-1,sizeof(par));
    memset(grp_sz,1,sizeof(grp_sz));

    int n,m;cin>>n>>m;
    int ans=0;
    while (m--)
    {
        int u,v;cin>>u>>v;
        int leaderU = find(u);
        int leaderV = find(v);
        if(leaderU==leaderV){
            ans++;
        }
        else{
            Union_by_size(u,v);
        }
    }
    cout<<ans<<nl;
    
    
    return 0;
}