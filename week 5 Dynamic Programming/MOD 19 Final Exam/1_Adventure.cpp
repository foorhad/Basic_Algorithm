#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e3 + 5;
using namespace std;

int num[N],weight[N];
int dp[N+1][N+1];

int knaspack(int n, int W){
    if(n==0 || W==0) return 0;
    
    if(dp[n][W]!=-1)return dp[n][W];

    if(weight[n-1] <= W){
        return dp[n][W] =max( knaspack(n-1,W-weight[n-1])+num[n-1], knaspack(n-1,W)); 
    }
    else {
        return dp[n][W] = knaspack(n-1,W);
    }  
}

int main()
{
 fast();
    int tc;cin>>tc;

    while(tc--){
        memset(dp,-1,sizeof(dp));

        int n,W;cin>>n>>W;
        
        for (int i = 0; i < n; i++)
        {
            cin>>weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
        }
        cout<<knaspack(n,W)<<nl;;
        
    }
    return 0;
}