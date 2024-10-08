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
    int n;
    cin >> n;
    int num[n];
    int s = 0;
    bool dp[1005][1005];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        s += num[i];
    }

    if (s % 2 == 0)
    {

        int sum = s / 2;
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) dp[1][i] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (num[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - num[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if(dp[n][sum])cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
    else
    {
        cout << "NO" << nl;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<nl;
    }

    return 0;
}