#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;

int main()
{
 fast();
    int n;cin>>n;
    int num[n];
    int s = 0;
    for (int i = 0; i < n; i++){
        cin>>num[i];
        s+=num[i];
    }
    bool dp[n+1][s+1];
    dp[0][0] = true;
    for(int i=1;i<=s;i++)dp[0][i]=false;

    for (int i = 1; i <= n; i++)
    {
        for (int j=0; j <= s; j++)
        {
            if(num[i-1] <= j){
                dp[i][j] = dp[i-1][j-num[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            } 
        }     
    }
    vector<int>v;
    for(int i=0;i<=n;i++){
        for (int j = 0; j <= s; j++)
        {
           if(dp[i][j]==1)v.push_back(j);
        }
    }
    int ans = INT_MAX;
    for(int val:v){
        int s1 = val;
        int s2 = s - s1;
        ans = min(ans,abs(s1-s2));
    }
    cout<<ans<<nl;
   
    return 0;
}