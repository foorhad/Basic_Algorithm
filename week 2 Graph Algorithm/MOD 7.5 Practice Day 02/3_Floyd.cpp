#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int main()
{
    fast();
    int n;
    cin >> n;
    int grid[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]==-1)grid[i][j]=INT_MAX;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (grid[i][k]!=INT_MAX && grid[k][j]!= INT_MAX && grid[i][k] + grid[k][j] < grid[i][j])
                {
                    grid[i][j] = grid[i][k] + grid[k][j];
                }
            }
        }
    }
    int max_dis = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] > max_dis && grid[i][j]!=INT_MAX)
            {
            max_dis = grid[i][j];
            }
        }
    }
    cout << max_dis << nl;
    return 0;
}
