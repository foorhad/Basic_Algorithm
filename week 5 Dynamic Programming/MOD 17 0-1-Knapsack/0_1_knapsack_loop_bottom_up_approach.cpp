#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int main()
{
    fast();
    int n, w;
    cin >> n >> w;
    int weight[n], value[n];
    int dp[n + 1][w + 1];

    // input
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    // assign 0 in 0 row and 1 column
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // bottom up approach
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                int opt1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                int opt2 = dp[i - 1][j];
                dp[i][j] = max(opt1, opt2);
            }
            else
            {
                int opt2 = dp[i - 1][j];
                dp[i][j] = opt2;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }

    // cout << dp[n][w] << nl;

    return 0;
}