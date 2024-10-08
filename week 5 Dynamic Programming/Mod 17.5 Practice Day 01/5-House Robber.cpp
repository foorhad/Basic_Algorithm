class Solution {
public:
    int dp[105];
    int solution(int n, vector<int>& nums){
        if(n < 0)return 0;
        if(dp[n]!=-1)return dp[n];
        int opt1 = nums[n] + solution(n-2,nums);
        int opt2 = solution(n-1,nums);
        return dp[n] = max(opt1,opt2);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solution(nums.size()-1,nums);
    }
};