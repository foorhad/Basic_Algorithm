
int mod = 1e9 + 7;
int findWays(vector<int> &arr, int k)
{

    long long int n = arr.size();
    long long int dp[105][100005];
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            }
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }

    return dp[n][k] % mod;
}
