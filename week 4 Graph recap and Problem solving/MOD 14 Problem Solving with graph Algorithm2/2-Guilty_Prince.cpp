#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll, ll>
#define nl '\n'
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
const int N = 1e6 + 5;
using namespace std;

int w, h;
char grid[21][21];
bool vis[50][50];
int re = 0;
vector<pi> direc = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i >= 0 && i < h && j >= 0 && j < w)
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    re++;
    for (auto child : direc)
    {
        int child_i = child.first + si;
        int child_j = child.second + sj;
        if (valid(child_i, child_j) && !vis[child_i][child_j] && grid[child_i][child_j] != '#')
        {
            dfs(child_i, child_j);
        }
    }
}
int main()
{
    fast();
    int tc;
    cin >> tc;
    for (int k = 1; k <= tc; k++)
    {
        cin >> w >> h;
        int si, sj;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '@')
                {
                    si = i, sj = j;
                }
            }
        }

        memset(vis, false, sizeof(vis));
        dfs(si,sj);
        cout << "Case " << k << ": " << re<<nl;
        re = 0;
    }

    return 0;
}