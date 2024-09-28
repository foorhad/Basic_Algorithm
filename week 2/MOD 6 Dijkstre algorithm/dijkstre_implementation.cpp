#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, e;
int dis[100];
vector<pair<int, int>> adj[100];

void dijkstre(int src){
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[0]=0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int parent = par.first; 
        int cost = par.second;

        for (auto p : adj[parent]){
            int childNode = p.first;
            int childCost = p.second;
            int total_cost = cost + childCost;
            if(total_cost < dis[childNode]){
                //path relax
                dis[childNode]=total_cost;
                q.push({childNode,total_cost});
            }
            
        }
    }
}
int main()
{
    fast();
    cin >> n >> e;
    while (e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)dis[i]=INT_MAX;
   
    dijkstre(0);
    for (int i = 0; i < n; i++){
    cout<<i<<"->"<<dis[i]<<endl;
    }
   

    return 0;
}