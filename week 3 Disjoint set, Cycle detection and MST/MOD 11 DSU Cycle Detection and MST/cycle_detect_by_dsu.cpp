#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
using namespace std;
const int N = 1e5+5;
int par[N];
int level[N];
void init(int n){
    for(int i=0;i<=n;i++)
        par[i]=-1,level[i]=0;
}
int find(int node){
    if(par[node] == -1)return node;
    else
    {
        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }
}
void Union_by_level(int n1, int n2){
    int leaderA = find(n1);
    int leaderB = find(n2);
    if(level[leaderA] > level[leaderB]){
        par[leaderB] = leaderA;
    }
    else if(level[leaderB] > level[leaderA]){
        par[leaderA] = leaderB;
    }
    else{
        par[leaderB] = leaderA;
        level[leaderA]++;
    }
}
int main()
{
 fast();
    bool cycle= false;
    int n,e;cin>>n>>e;
    init(n);
    while (e--)
    {
        int a,b;cin>>a>>b;
        int leaderA = find(a);
        int leaderB = find(b);
        if(leaderA==leaderB)cycle=true;
        else{
            Union_by_level(a,b);
        }
    }
    if(cycle)cout<<"cycle found"<<endl;
    else cout<<"cycle not found"<<nl;
    
    return 0;
}