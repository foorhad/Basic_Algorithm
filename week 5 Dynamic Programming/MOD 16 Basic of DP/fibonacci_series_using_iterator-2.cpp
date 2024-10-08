#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;


int main()
{
 fast();
    ll n;cin>>n;
    ll dp[n+5];
    dp[0]=0,dp[1]=1;
    for (ll i = 2; i <= n; i++)
    {
        ll ans = dp[i-1]+dp[i-2];
        dp[i]=ans;
    }
    cout<<dp[n]<<nl;
    
    return 0;
}