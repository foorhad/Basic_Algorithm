#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const long long int INF = 1e18;
int nodes, edge;

vector<pair<int,int>> adj[100005];
long long int dis[100005];
long long  int parrent_array[100005];
bool vis[100005];

void dijkstre(int src){
    for (int i = 1; i <= nodes; i++) dis[i] = INF; //assighn infinite value in dis array
       
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});

    while (!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();

        int parentNode = p.second;
        int parentCost = p.first;

        vis[parentNode]=true;

        for (auto child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;
            
            // path relax
            if (dis[parentNode]+ childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
                pq.push({dis[childNode], childNode});
                parrent_array[childNode] = parentNode;
            }
        }
    }
}
int main()
{
    fast();
    cin >> nodes >> edge;
    while (edge--)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    int src = 1;
   
    dijkstre(src);


    if(!vis[nodes]){
        cout<<-1<<endl;
        return 0;
    }

    vector<int>path;
    int crnt = nodes;
    while(1){
        if(crnt==0)break;
        path.push_back(crnt);
        crnt= parrent_array[crnt];
    }
    reverse(path.begin(),path.end());
    for(auto val : path)cout<<val<<" ";

    return 0;
}