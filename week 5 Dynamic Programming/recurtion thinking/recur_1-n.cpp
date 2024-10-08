#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

void recur(int n)
{   
    if(n==0)return;
    recur(n-1);
    cout<<"hello->" << n << nl;
}

int main()
{
    fast();
    int n;
    cin >> n;
    recur(n);
    return 0;
}