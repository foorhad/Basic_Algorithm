class Solution
{
public:
    int row, col;
    int ans = 0;
    bool vis[100][100];
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
        ans++;
        for (pair child : v)
        {
            int child_i = child.first + i;
            int child_j = child.second + j;

            if (valid(child_i, child_j) && !vis[child_i][child_j] && grid[child_i][child_j] == 1)
            {
                vis[child_i][child_j] = true;
                dfs(child_i, child_j, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_island = 0;
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    ans = 0;
                    dfs(i, j, grid);
                    max_island = max(max_island, ans);
                }
            }
        }
        return max_island;
    }
};