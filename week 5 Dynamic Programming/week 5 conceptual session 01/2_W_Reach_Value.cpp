#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

ll n;
bool recur(ll a)
{
    if (a == n)
        return true;
    if (a > n)
        return false;
    return recur(a * 10) || recur(a * 20);
}

int main()
{
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool flag = recur(1);
        if (flag)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }

    return 0;
}