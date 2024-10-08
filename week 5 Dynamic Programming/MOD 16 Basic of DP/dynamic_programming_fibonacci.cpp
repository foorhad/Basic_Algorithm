#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

//memoization approach
ll dp[N];
ll fibo(ll n)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    fast();
    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;
    cout << fibo(n) << nl;
    
    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    return 0;
}