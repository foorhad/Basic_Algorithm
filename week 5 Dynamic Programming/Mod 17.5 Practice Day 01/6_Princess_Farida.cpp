#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e4 + 5;
using namespace std;
ll dp[N];
ll knapsack(ll n, ll num[]){
    if(n < 0)return 0;
    if(dp[n]!=-1)return dp[n];
    ll opt1 = num[n]+knapsack(n-2,num);
    ll opt2 = knapsack(n-1,num);
    return dp[n] = max(opt1,opt2);
}

int main()
{
 fast();
    int tc;cin>>tc;
    for (int i = 1; i <= tc; i++)
    {
        memset(dp,-1,sizeof(dp));
        ll n;cin>>n;
        ll num[N];
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
        }
        cout<<"Case "<<i<<": "<<knapsack(n-1,num)<<nl;
    }
    
    return 0;
}