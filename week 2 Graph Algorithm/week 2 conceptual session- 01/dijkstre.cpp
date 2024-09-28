#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int nodes, edge;

vector<pair<int, int>> adj_list[1000];
int dis[1000];
int parent_array[1000];
void dijkstre(int src)
{

    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[0], src});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int parentNode = p.second;
        int parentCost = p.first;

        for (auto child : adj_list[parentNode])
        {
            int childNode = child.second;
            int childCost = child.first;

            // path relax
            if (parentCost + childCost < dis[childNode])
            {
                parent_array[childNode] = parentNode;
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({c, b});
        adj_list[b].push_back({c, a});
    }

    for (int i = 1; i <= nodes; i++)
        dis[i] = INT_MAX;
    // memset(parent_array,-1,sizeof(parent_array));

    int src = 1;
    dijkstre(src);

    // for(int i=1; i<=nodes; i++)cout<<i<<"->"<<dis[i]<<endl;

    int current = nodes;
    vector<int>path;
    while (1)
    {
        path.push_back(current);
        if(current==src)break;
        current=parent_array[current];
    }
    reverse(path.begin(),path.end());
    for(int val : path)cout<<val<<" ";

    return 0;
}