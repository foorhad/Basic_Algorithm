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

int knaspack(int n, int s)
{

    if (n == 0)
    {
        if (s == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    if(dp[n][s]!=-1)return dp[n][s];
    if (num[n - 1] <= s)
    {
        int opt1 = knaspack(n - 1, s - num[n - 1]);
        int opt2 = knaspack(n - 1, s);
        return dp[n][s] = opt1 + opt2;
    }
    else
    {
        return dp[n][s] = knaspack(n - 1, s);
    }
}

int main()
{
    fast();
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int s;
    cin >> s;
    cout << knaspack(n, s) << nl;


    return 0;
}