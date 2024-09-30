class Solution {
public:
    int store;
    int row,col;
    bool vis[55][55];
    vector<pair<int,int>> move = { {0,1}, {0,-1}, {-1,0}, {1,0} };
    bool valid(int i, int j){
        if(i>=0 && i<row && j>=0 && j<col)return true;
        return false;
    }
    void dfs(int sr, int sc, int color, vector<vector<int>>& image){
        vis[sr][sc]=true;
        image[sr][sc]=color;
        for(auto child : move){
            int child_i = child.first + sr;
            int child_j = child.second + sc;
            if(valid(child_i,child_j) && !vis[child_i][child_j] && image[child_i][child_j]==store){
                dfs(child_i,child_j,color,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(vis,false,sizeof(vis));
        store= image[sr][sc];
        row = image.size();
        col = image[0].size();
        dfs(sr,sc,color,image);
    return image;
    }
};
