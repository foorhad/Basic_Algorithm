#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const long long int INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;
ll n;
bool recur(ll i){
    if(i==n)return true;
    if(i>n)return false;
    return recur(i*10) || recur(i*20);
}
int main()
{
 fast();
    int tc;cin>>tc;
    while (tc--)
    {
        cin>>n;
        bool flag = recur(1);
        if(flag)cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
    
    return 0;
}