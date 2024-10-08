class Solution
{
public:
    int dp[50];
    int fibo(int n)
    {
        if (n == 1 || n == 2)
            return n;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            int ans = fibo(n - 1) + fibo(n - 2);
            return dp[n] = ans;
        }
    }
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return fibo(n);
    }
};