#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int n, x;
int a[25];
 
bool recur(int i,int sum)
{
    if (i == n)
    {
        return sum == x;
    }
 
    bool op1 = recur(i + 1,sum + a[i]);
    bool op2 = recur(i + 1,sum - a[i]);
 
    return op1 || op2;
}
 
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
 
    if (recur(1,a[0]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}


