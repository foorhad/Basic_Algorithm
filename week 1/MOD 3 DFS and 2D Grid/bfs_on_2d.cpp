#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int r, c;
char mat[20][20];
bool vis[1005][1005] = {false};
int dis[1005][1005];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int i = parent.first;
        int j = parent.second;
        cout<<i<<" "<<j<<endl;
        for (auto x : v)
        {
            int child_i = i + x.first, child_j = j + x.second;
            if (valid(child_i, child_j) && vis[child_i][child_j] == false)
            {
                q.push({child_i,child_j});
                vis[child_i][child_j] = true;
                dis[child_i][child_j] = dis[i][j] + 1;
            }
        }
    }
}
int main()
{
    fast();
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(dis, -1, sizeof(dis));
    bfs(0, 0);
    cout << dis[0][3] << endl;

    return 0;
}