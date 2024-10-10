#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

class Edges
{
public:
    int u, v, c;
    Edges(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int dis[N];
    vector<Edges> edgelist;
    while (m--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgelist.push_back(Edges(u, v, c));
    }
    for (int i = 1; i <= n; i++)
        dis[i] =  30000;
    dis[1]=0;
    for (int i = 0; i < n - 1; i++)
    {
        for (Edges n : edgelist)
        {
            if(dis[n.u]!= 30000 && dis[n.u]+n.c < dis[n.v]){
                dis[n.v] = dis[n.u]+n.c;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
}
