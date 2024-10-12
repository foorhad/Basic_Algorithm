class Solution {
public:
    int r,c;
    bool vis[110][110];
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int i, int j)
    {
        if (i >= 0 && i < r && j >= 0 && j < c)return true;
        return false;
    }
    int par=0;
    void dfs(int i, int j, vector<vector<int>>& grid){
        vis[i][j]=true;
        for(auto c : v){
            int child_i = c.first + i;
            int child_j = c.second + j;
            if(!valid(child_i,child_j) || grid[child_i][child_j]==0)par++;
            if(valid(child_i,child_j) && !vis[child_i][child_j] && grid[child_i][child_j]==1){

            }
        }

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        r = grid.size();
        c = grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                 dfs(i,j,grid);
                }
            }
        }
    return par;
    }
};
