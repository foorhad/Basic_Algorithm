#include <bits/stdc++.h>
#define ll long long int
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const long long int INF = 1e18 + 5;
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
pair<int, int> parent[1005][1005];

vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#')
        return true;
    return false;
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;
    dis[i][j] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int parent_i = p.first;
        int parent_j = p.second;

        for (auto c : v)
        {
            int child_i = c.first + parent_i;
            int child_j = c.second + parent_j;

            if (valid(child_i, child_j) && !vis[child_i][child_j])
            {
                vis[child_i][child_j] = true;
                q.push({child_i, child_j});
                parent[child_i][child_j] = {parent_i, parent_j};
                dis[child_i][child_j] = dis[parent_i][parent_j] + 1;
            }
        }
    }
}

int main()
{
    fast();
    memset(dis, -1, sizeof(dis));
    cin >> n >> m;

    int si, sj, ei, ej;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;sj = j;
            }
            if (grid[i][j] == 'B')
            {
                ei = i;ej = j;
            }
        }
    }
    bfs(si, sj);

    if (vis[ei][ej])
    {
        cout << "YES" << endl;
        cout << dis[ei][ej] << endl;
        
        pair<int, int> p = {ei, ej};
        vector<pair<int, int>> path;
        while (!(p.first == si && p.second == sj))
        {
            path.push_back({p.first, p.second});
            p = parent[p.first][p.second];
        }
        path.push_back({si, sj});
        reverse(path.begin(), path.end());
        string ans;
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                // RL
                if (path[i - 1].second + 1 == path[i].second)
                {
                    // R
                    ans += "R";
                }
                else
                {
                    // L
                    ans += "L";
                }
            }
            else
            {
                // UD
                if (path[i - 1].first + 1 == path[i].first)
                {
                    // D
                    ans += "D";
                }
                else
                {
                    //U
                    ans += "U";
                }
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}