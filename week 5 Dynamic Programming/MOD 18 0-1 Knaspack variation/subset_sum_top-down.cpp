#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int num[1005];
int dp[1005][1005];

bool knaspack(int n, int sum){

    if(n==0){
        if(sum==0){
            return true;
        }
        else return false;
    }

    if(dp[n][sum] != -1)return dp[n][sum];

    if(num[n-1] <= sum){
        bool opt1 = knaspack(n-1,sum-num[n-1]);
        bool opt2 = knaspack(n-1,sum);
        return dp[n][sum] = opt1 || opt2;
    }
    else{
        bool opt2 = knaspack(n-1,sum);
        return dp[n][sum] = opt2;
    }
}

int main()
{
 fast();
    memset(dp,-1,sizeof(dp));

    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    int sum;cin>>sum;

    if(knaspack(n,sum))cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
    return 0;
}