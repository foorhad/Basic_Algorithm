class Solution {
public:
    vector<pair<int,int>>adj_list[105];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {    
        for(auto val : times){
            int u = val[0];
            int v = val[1];
            int w = val[2];
            adj_list[u].push_back({w,v});
        }
        int dis[105];
        for(int i=1;i<=n;i++)dis[i]=INT_MAX;

        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            pair<int,int> p = pq.top();pq.pop();
            int parent = p.second;
        
            for(auto c : adj_list[parent]){
                int child = c.second;
                int child_cost = c.first;
                if(dis[parent]+child_cost < dis[child]){
                    dis[child] = dis[parent]+child_cost;
                    pq.push({dis[child],child}); 
                }
            }
        }
        int max_val = INT_MIN;
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX)flag=false;
            if(dis[i]>max_val && dis[i]!=INT_MAX){
                max_val = dis[i];
            }
        }
    if(flag)return  max_val;
    return -1;
    }
};
