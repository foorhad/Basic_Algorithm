class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int s = 0;
        for (int val : nums)
            s += val;

        if (s % 2 == 0)
        {
            int sum = s / 2;
            int n = nums.size();
            bool dp[1005][20005];
            dp[0][0] = true;
            for (int i = 1; i <= n; i++)
                dp[1][i] = false;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (nums[i - 1] <= j)
                    {
                        bool opt1 = dp[i - 1][j - nums[i - 1]];
                        bool opt2 = dp[i - 1][j];
                        dp[i][j] = opt1 || opt2;
                    }
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            return dp[n][sum];
        }
        else
        {
            return false;
        }
    }
};