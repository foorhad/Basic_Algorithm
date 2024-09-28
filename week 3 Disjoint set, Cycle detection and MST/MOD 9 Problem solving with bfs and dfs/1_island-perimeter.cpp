class Solution {
public:
    int row,col;
    int ans=0;
    bool vis[105][105];
    vector<pair<int,int>>v={{0,1},{0,-1},{-1,0},{1,0}};
    bool valid(int i, int j){
        if(i>=0 && i<row && j>=0 && j<col)return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>>& grid){
        vis[i][j]=true;
        for(auto child : v){
            int childi = child.first+i;
            int childj = child.second+j;

            if(valid(childi,childj)){
                if(grid[childi][childj]==0)ans++;
            }
            else ans++;

            if(valid(childi, childj) && !vis[childi][childj] && grid[childi][childj]){
                dfs(childi, childj,grid);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0; j<col; j++){
                if(!vis[i][j] && grid[i][j]==1)
                    dfs(i,j,grid); 
            }
        }
    return ans;
    }
};