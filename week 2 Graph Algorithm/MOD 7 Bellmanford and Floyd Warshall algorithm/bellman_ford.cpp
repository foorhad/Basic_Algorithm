#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    fast();
    int nodes, edge;
    cin >> nodes >> edge;

    long long int dis[nodes + 5];
    for (int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;
    vector<Edge> edgelist;

    while (edge--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgelist.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= nodes-1; i++)
    {
        for (auto pair : edgelist)
        {
            int u = pair.u;
            int v = pair.v;
            int c = pair.c;
            //path relaxation
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    // output
    for (int i = 0; i < nodes; i++)
        cout << i << "->" << dis[i] << endl;

    return 0;
}