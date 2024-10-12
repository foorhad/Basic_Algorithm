class Solution {
public:
    int r,c;
    vector<int>adj_list[200020];
    bool vis[200020];
    void dfs(int s){
        vis[s]=true;
        for(int val : adj_list[s]){
            if(!vis[val]){
                dfs(val);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        memset(vis,false,sizeof(vis));
        for(auto val : edges){
            int u = val[0];
            int v = val[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        dfs(source);


    return vis[destination];
    }
};
