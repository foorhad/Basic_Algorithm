#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

void pattern_print(int n)
{
    if (n == 1){
        cout<<1<<nl;
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << nl;
    pattern_print(n - 1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << nl;
    
}

int main()
{
    fast();
    int n;
    cin >> n;
    pattern_print(n);
    return 0;
}