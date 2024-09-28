class Solution {
public:
    int cnt=0;
    bool vis[1005][1005]={false};
    int flag=0;

    bool valid(int i, int j,int row, int col){
    if (i >= 0 && i<row && j>=0 && j<col)return true;
    else return false;
    }

    void bfs(vector<vector<int>>& grid,int si, int sj){
        int row = grid.size();
        int col = grid[0].size();
        
        vector<pair<int, int>> xy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int,int>>q;
        q.push({si,sj});
        vis[si][sj]=true;

        while(!q.empty()){
            pair<int,int>node=q.front(); q.pop();
            int r= node.first;
            int c= node.second;

            for(auto child : xy){
                int i=r+child.first;
                int j=c+child.second;

                if(!valid(i,j,row,col)) flag=1;
            
                if(valid(i,j,row,col) && !vis[i][j] && grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        if(flag == 1)cnt--;
        flag=0;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        }
    return cnt;  
    }
};