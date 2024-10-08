#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

ll n, m;
ll grid[12][12];
ll dp[12][12];

ll kanpsack(ll i, ll j)
{
    if(i==n && j==m){
        return grid[i][j];
    }
    if (i > n || j > m)
        return INT_MIN;

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = grid[i][j] + max(kanpsack(i + 1, j), kanpsack(i, j + 1));
}

int main()
{
    fast();
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << kanpsack(1, 1);

    return 0;
}