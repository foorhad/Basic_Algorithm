#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int weight[22],value[105];
int dp[110][110];

int  knaspack(int n,int W){
    if(n<0 || W<0)return 0;

    if(dp[n][W] != -1)return dp[n][W];

    if(weight[n] <= W){
        //nibo
        int opt1 = knaspack(n-1,W-weight[n])+value[n];
        int opt2 = knaspack(n-1,W);
        return max(opt1,opt2);
    }
    else{
        //niob na
        int opt2 = knaspack(n-1,W);
        return opt2;
    }
}

int main()
{
 fast();
    memset(dp,-1,sizeof(dp));
    
    int n,W;cin>>n>>W;
    
    for (int i = 0; i < n; i++)
    {
        int w,v;cin>>w>>v;
        weight[i]=w;
        value[i]=v;
    }
    cout<< knaspack(n-1,W);
    
    return 0;
}