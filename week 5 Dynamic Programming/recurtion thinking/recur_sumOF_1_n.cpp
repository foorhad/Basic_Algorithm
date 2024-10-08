#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int recur(int n)
{
    if (n == 0)
        return 0;
    return recur(n - 1) + n;
}

int main()
{
    fast();
    cout << recur(5);
    return 0;
}