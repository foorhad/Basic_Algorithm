#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll INF = 1e18+5;
const int N = 1e6 + 5;
using namespace std;


int main()
{
 fast();
    ll n;cin>>n;
    ll a=0, b=1;
    cout<<a<<" "<<b<<" ";
    for (ll i = 2; i <= n ; i++)
    {
        ll c = a+b;
        cout<<c<<" ";
        a = b, b=c;
    }
    
    return 0;
}