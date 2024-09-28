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
    void bfs(int i, int j, vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty())
        {
            pair<int, int> pa = q.front();
            q.pop();
            int parent_i = pa.first;
            int parent_j = pa.second;
            if (parent_i == 0 || parent_i == row - 1 || parent_j == 0 || parent_j == col - 1)
                ans = false;
            for (pair p : v)
            {
                int child_i = parent_i + p.first;
                int child_j = parent_j + p.second;
                // if(!valid(child_i,child_j))ans=false;

                if (valid(child_i, child_j) && !vis[child_i][child_j] && grid[child_i][child_j] == 0)
                {
                    vis[child_i][child_j] = true;
                    q.push({child_i, child_j});
                }
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
                    bfs(i, j, grid);
                    if (ans)
                        close_island++;
                }
            }
        }
        return close_island;
    }
};