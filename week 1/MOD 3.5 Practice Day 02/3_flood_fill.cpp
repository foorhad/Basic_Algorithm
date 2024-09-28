class Solution {
public:
   bool valid(int i, int j,int row, int col){
    if (i >= 0 && i<row && j>=0 && j<col)return true;
    else return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();

        bool vis[1005][1005]={false};

        int store = image[sr][sc];

        vector<pair<int, int>> xy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        image[sr][sc]=color; //color update
        while(!q.empty()){
            pair<int,int>node=q.front(); q.pop();
            int r= node.first;
            int c=node.second;

            for(auto child : xy){
                int i=r+child.first;
                int j=c+child.second;
                if(valid(i,j,row,col) && !vis[i][j] && image[i][j]==store){
                    image[i][j]=color;
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        return image;
    }
};