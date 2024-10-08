#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

ll n;
int dp[N];
bool knaspack(ll a)
{
    if (a == n)
        return true;
    if (a > n)
        return false;
    if(dp[a]!=-1)return dp[a];
    return dp[a] = knaspack(a + 3) || knaspack(a * 2);
}
int main()
{
    fast();
    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(dp,-1,sizeof(dp));
        cin >> n;
        bool flag = knaspack(1);
        if (flag)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }
    return 0;
}