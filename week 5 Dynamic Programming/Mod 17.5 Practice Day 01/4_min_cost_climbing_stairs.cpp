class Solution {
public:
    int dp[1005];
    int knapsack(int sz,vector<int> cost){
        if(sz==0 || sz==1)return 0;
        if(dp[sz]!=-1)return dp[sz];
        int opt1 = knapsack(sz-1,cost)+cost[sz-1] ;
        int opt2 = knapsack(sz-2,cost)+cost[sz-2];
        return dp[sz] = min(opt1,opt2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return knapsack(n,cost);
    }
};