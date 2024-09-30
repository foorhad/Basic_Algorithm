#include <bits/stdc++.h>
class Solution {
public:
    bool flag=true;
    int island = 0;
    int row,col;
    bool vis[110][110];
    vector<pair<int,int>> movem = { {0,1}, {0,-1}, {-1,0}, {1,0} };

    bool valid(int i, int j){
        if(i>=0 && i<row && j>=0 && j<col)return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<int>>&grid){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int> parent = q.front();
            q.pop();
            for(auto child : movem){
                int child_i = child.first + parent.first;
                int child_j = child.second + parent.second;

                if(!valid(child_i,child_j))flag=false;
                
                if(valid(child_i,child_j) && !vis[child_i][child_j] && grid[child_i][child_j]==0){
                    q.push({child_i,child_j});
                    vis[child_i][child_j]=true;
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        row = grid.size();
        col = grid[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(i,j,grid);
                    if(flag)island++;
                    flag = true;
                }
            }
        }
    return island;
    }
};
