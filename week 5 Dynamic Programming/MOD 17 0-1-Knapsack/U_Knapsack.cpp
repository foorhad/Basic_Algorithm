#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int dp[1005][1005];

int knaspack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;
    if(dp[n][W]!=-1)return dp[n][W];
    if (weight[n - 1] <= W)
    {
        int opt1 = knaspack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];
        int opt2 = knaspack(n - 1, weight, value, W);
        return dp[n][W] = max(opt1, opt2);
    }
    else
    {
        int opt2 = knaspack(n - 1, weight, value, W);
        return dp[n][W] = opt2;
    }
}

int main()
{
    fast();
    int n,W;
    cin >> n>> W;
    memset(dp, -1, sizeof(dp));

    int weight[n], value[n];
   for (int i = 0; i < n; i++)
   {
        int w,v;cin>>w>>v;
        weight[i]=w;
        value[i]=v;
   }
    cout << knaspack(n, weight, value, W)<<nl;



    return 0;
}