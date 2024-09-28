class Solution
{
public:
    int row, col;
    bool vis[305][305];
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int i, int j)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        vis[i][j] = true;
        for (pair child : v)
        {
            int child_i = child.first + i;
            int child_j = child.second + j;
            if (valid(child_i, child_j) && !vis[child_i][child_j] && grid[child_i][child_j] == '1')
            {
                vis[child_i][child_j] = true;
                dfs(child_i, child_j, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count_island = 0;
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    count_island++;
                    dfs(i, j, grid);
                }
            }
        }
        return count_island;
    }
};