#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;

using namespace std;
int main()
{
    fast();
    ll n, e;
    cin >> n >> e;
    ll mat[n+1][n+1];

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            mat[i][j] = INF;
            if (i == j)
                mat[i][j] = 0;
        }
    }
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        mat[u][v] = min(mat[u][v], c);
    }

    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }

    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll x, y;
        cin >> x >> y;
        if (mat[x][y] == INF)
            cout << -1<<endl;
        else
            cout << mat[x][y] << endl;
    }

    return 0;
}