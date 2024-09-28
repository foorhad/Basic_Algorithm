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
    void dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        vis[i][j] = true;
        if (grid1[i][j] == 0)
            ans = false;
        for (pair p : v)
        {
            int child_i = p.first + i;
            int child_j = p.second + j;
            if (valid(child_i, child_j) && !vis[child_i][child_j] && grid2[child_i][child_j] == 1)
            {
                dfs(child_i, child_j, grid1, grid2);
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
                    dfs(i, j, grid1, grid2);
                    if (ans)
                        cnt_island++;
                }
            }
        }
        return cnt_island;
    }
};