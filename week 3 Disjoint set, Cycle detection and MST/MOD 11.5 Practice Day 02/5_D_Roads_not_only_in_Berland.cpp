#include <bits/stdc++.h>
#define ll long long int
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;

const int N = 1e3 + 5;
int par[N];
int grp_size[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = -1, grp_size[i] = 1;
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
void Union_by_sz(int n1, int n2)
{
    int leaderA = find(n1);
    int leaderB = find(n2);
    if (grp_size[leaderA] > grp_size[leaderB])
    {
        par[leaderB] = leaderA;
        grp_size[leaderA] += grp_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        grp_size[leaderB] += grp_size[leaderA];
    }
}

int main()
{
    fast();
    vector<pair<int, int>>reject,need;
    int n;cin >> n;
    int m = n - 1;
    init(n);
    while (m--){
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB){
            reject.push_back({a, b});
        }
        else{
            Union_by_sz(a, b);
        }
    }
    cout<<reject.size()<<nl;
    for(pair<int,int> grp : reject)cout<<grp.first<<" "<<grp.second<<nl;
    // for (int i = 2; i <= n; i++){
    //     int la = find(1);
    //     int lb = find(i);
    //     if (la != lb){
    //         need.push_back({1,i});
    //         Union_by_sz(1,i);
    //     }
    // }
    // cout << reject.size() << nl;
    // for (int k = 0; k < reject.size(); k++){
    //     cout << reject[k].first << " " << reject[k].second << " " << need[k].first << " " << need[k].second << nl;
    // }

    return 0;
}