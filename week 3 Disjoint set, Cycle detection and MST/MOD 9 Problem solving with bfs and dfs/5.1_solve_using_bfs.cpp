class Solution
{
public:
    int row, col;
    bool vis[505][505];
    bool ans;
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }
    void bfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        if (grid1[i][j] == 0)
            ans = false;
        while (!q.empty())
        {
            pair<int, int> pa = q.front();
            q.pop();
            int parent_i = pa.first;
            int parent_j = pa.second;

            if (grid1[parent_i][parent_j] == 0)
                ans = false;

            for (pair p : v)
            {
                int child_i = p.first + parent_i;
                int child_j = p.second + parent_j;

                if (valid(child_i, child_j) && !vis[child_i][child_j] && grid2[child_i][child_j] == 1)
                {
                    vis[child_i][child_j] = true;
                    q.push({child_i, child_j});
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int cnt_island = 0;
        row = grid1.size();
        col = grid1[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid2[i][j] == 1)
                {
                    ans = true;
                    bfs(i, j, grid1, grid2);
                    if (ans)
                        cnt_island++;
                }
            }
        }
        return cnt_island;
    }
};