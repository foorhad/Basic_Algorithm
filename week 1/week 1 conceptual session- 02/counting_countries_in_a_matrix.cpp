#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int r, c;
char mat[1001][1001];
bool vis[1001][1001] = {false};
vector<pair<int, int>> xy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // movement
bool valid(int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c && mat[i][j] == '.')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    // cout<<si<<" "<<sj<<endl;
    vis[si][sj] = true;
    for (auto p : xy)
    {
        int f = si + p.first;
        int s = sj + p.second;
        if (valid(f, s) && vis[f][s] == false)
            dfs(f, s);
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty()){
        pair<int,int>node =q.front();q.pop();
        int nrow = node.first;
        int ncol = node.second;

        for (auto p : xy){
            int f = nrow + p.first;
            int s = ncol + p.second;
            if (valid(f, s) && !vis[f][s]){
                vis[f][s]=true;
                q.push({f,s});
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
    // dfs(0, 2);
    // cout << vis[2][2];

    // find compenent
    int cmp = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (valid(i, j) & !vis[i][j])
            {
                cmp++;
                // dfs(i,j);
                bfs(i, j);
            }
        }
    }
    cout << cmp;

    return 0;
}