#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

//top --> down approach
int fact(int n) //o(n) 
{
    if (n == 0)
        return 1;
    else
    {
        int ans = fact(n - 1);
        return ans * n;
    }
}

int main()
{
    fast();
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}