#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
// const int N=1e4+5;
int r, c;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int, int>> xy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // movement

bool valid(int i, int j){
    if (i >= 0 && i < r && j >= 0 && j < c)return true;
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
        int rowNode = parent.first;
        int colNode = parent.second;

        for (auto child : xy)
        {
            int i = rowNode + child.first;
            int j = colNode + child.second;
            if (valid(i, j) && vis[i][j] == false)
            {
                vis[i][j] = true;
                dis[i][j] = dis[rowNode][colNode] + 1;
                q.push({i, j});
            }
        }
    }
}

int main()
{
    fast();
    cin >> r >> c;
    char mat[r][c];
    memset(dis,-1,sizeof(dis));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    int source_row, source_column;
    cin >> source_row >> source_column;
    int destination_row, destination_column;

    cin >> destination_row >> destination_column;

    bfs(source_row, source_column); // source node

    if (vis[destination_row][destination_column])
    {
        cout << "shortest distance: " << dis[destination_row][destination_column] << endl;
    }
    else
        cout << "jawa jabe na" << endl;

    return 0;
}

