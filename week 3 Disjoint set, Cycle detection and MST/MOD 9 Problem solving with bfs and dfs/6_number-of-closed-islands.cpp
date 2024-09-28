class Solution
{
public:
    int row, col;
    int ans;
    bool vis[105][105];
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        vis[i][j] = true;

        for (pair p : v)
        {
            int child_i = i + p.first;
            int child_j = j + p.second;
            if (!valid(child_i, child_j))
                ans = false;
            if (valid(child_i, child_j) && !vis[child_i][child_j] && grid[child_i][child_j] == 0)
            {
                dfs(child_i, child_j, grid);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int close_island = 0;
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    ans = true;
                    dfs(i, j, grid);
                    if (ans)
                        close_island++;
                }
            }
        }
        return close_island;
    }
};