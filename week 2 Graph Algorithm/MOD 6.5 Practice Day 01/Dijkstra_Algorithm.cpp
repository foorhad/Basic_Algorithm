#include <bits/stdc++.h>
using namespace std;

int matrix[1005][1005];
vector<pair<int,int>> adj[1005];
int dis[1005];

void dijkstre(int src){
    queue<pair<int,int>>q;
    q.push({src,0});
    dis[src]=0;

    while(!q.empty()){
        pair<int,int> par = q.front(); q.pop();
        int Node = par.first;
        int cost = par.second;

        for(auto child : adj[Node]){
            int childNode = child.first;
            int childCost = child.second;

            if(cost+childCost < dis[childNode]){
                dis[childNode] = cost+childCost;
                q.push({childNode,dis[childNode]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int n,s,f;
    cin>>n>>s>>f;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>matrix[i][j];
        }
    }
 
    //convert adjacency matrix to adjacency list
   for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        if(matrix[i][j] > 0 ){
            adj[i].push_back({j,matrix[i][j]});
        }
    }
   }
   for(int i=1; i<=n; i++)dis[i]=INT_MAX;
   dijkstre(s);

   if(dis[f] == INT_MAX)cout<<-1;
   else cout<<dis[f];

}
