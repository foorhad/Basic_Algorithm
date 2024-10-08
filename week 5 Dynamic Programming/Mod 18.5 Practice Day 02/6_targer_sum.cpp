class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int s = 0;
        for (int val : nums)
            s += val;
        int s1 = (s + target) / 2;
        if (s1 < 0 || target > s || (s + target) % 2 != 0)
            return 0;
        else
        {
            int dp[25][20005];
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++)
                dp[0][i] = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= s1; j++)
                {
                    if (nums[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[n][s1];
        }
    }
};