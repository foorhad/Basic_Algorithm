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
    int dis[nodes];
    for (int i = 0; i < nodes; i++)
        dis[i] = INT_MAX;
    dis[0] = 0;
    vector<Edge> edgelist;
    while (edge--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgelist.push_back(Edge(u, v, c));
        edgelist.push_back(Edge(v, u, c));
    }

    for (int i = 0; i < nodes; i++)
    {
        for (Edge e : edgelist)
        {
            int u = e.u;
            int v = e.v;
            int c = e.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;
    for (Edge e : edgelist)
    {
        int u = e.u;
        int v = e.v;
        int c = e.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
        }
    }

    if (cycle)
        cout << "cycle found. no answer" << endl;
    else
    {
        for (int i = 0; i < nodes; i++)
            cout << i << "->" << dis[i] << endl;
    }

    return 0;
}