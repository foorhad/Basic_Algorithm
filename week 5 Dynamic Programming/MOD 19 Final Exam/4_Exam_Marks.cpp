#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e3 + 5;
using namespace std;

int main()
{
 fast();
    int tc;cin>>tc;
    while (tc--)
    {
        int n,m;cin>>n>>m;
        int num[1005];
        for(int i=0;i<n;i++)cin>>num[i];

        if(m==1000)cout<<"YES"<<nl;

        else{
            int tar = 1000 - m;
            bool dp[1005][1005]; 
            dp[0][0] = true;

            for (int i = 1; i <= n; i++) dp[0][i] = false;

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= tar; j++)
                {
                    if (num[i - 1] <= j)
                    {
                        dp[i][j] = dp[i - 1][j - num[i - 1]] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            if(dp[n][tar])cout<<"YES"<<nl;
            else cout<<"NO"<<nl;
        }
    }
    
    return 0;
}