class Solution
{
public:
    int dp[105];
    int recur(int n, vector<int> &nums)
    {
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int opt1 = nums[n] + recur(n - 2, nums);
        int opt2 = recur(n - 1, nums);
        return dp[n] = max(opt1, opt2);
    }

    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return recur(n - 1, nums);
    }
};