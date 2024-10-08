#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int num[1005];
int dp[1005][1005];

int main()
{
    fast();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int s;
    cin >> s;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (num[i - 1] <= j)
            {
                int opt1 = dp[i - 1][j - num[i - 1]];
                int opt2 = dp[i - 1][j];
                dp[i][j] = opt1 + opt2;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }

    cout << dp[n][s] << nl;

    return 0;
}